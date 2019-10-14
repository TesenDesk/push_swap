/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:19:16 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 20:46:03 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			dia_is_low_that(t_stack *a, int factor, int min, int max)
{
	while (a && a->i <= min)
		a = a->next;
	while (a && a->i < max)
	{
		if (a->i >= factor)
			return (0);
		a = a->next;
	}
	return (1);
}

void		dia_drop_bigger(t_hub *h, int half, int min, int max)
{
	while (!dia_is_low_that(h->a, half, min, max))
	{
		if (h->a->i >= half)
			push_stack(h, 1);
		else
			rotate_stack(h, 0);
	}
	fin_rot(h);
}

t_hub		*dia_bubble_sort(t_hub *h, int max)
{
	while (!stack_sorted(h->a))
	{
		while (!stack_sorted(h->a) && h->a->next->next->i < max)
		{
			if (h->a->i > h->a->next->i)
				swap_stack(h, 0);
			if (!stack_sorted(h->a))
				rotate_stack(h, 0);
		}
		if (h->a->i > h->a->next->i)
			swap_stack(h, 0);
		while (stack_get_last(h->a) < max)
		{
			reverse_stack(h, 0);
			if (h->a->i > h->a->next->i)
				swap_stack(h, 0);
		}
	}
	return (h);
}

void		dia_return(t_hub *h, int min)
{
	while (h->b && h->b->i > min)
		push_stack(h, -1);
}

void		dia_prereturn(t_hub *h, int min, int max)
{
	int	half;

	if (stack_len(h->b) > MIN_STACK)
	{
		half = dia_center(h->b, min, max);
		add_bigger(h, half);
		dia_f_a(h, half, max);
		dia_prereturn(h, min, half + 1);
	}
	else
	{
		dia_return(h, min);
		if (!stack_sorted(h->a))
			dia_bubble_sort(h, max);
	}
}
