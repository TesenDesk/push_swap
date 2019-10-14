/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:26:54 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 21:06:22 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_hub	*bubble_sort(t_hub *h)
{
	int b;

	b = stack_biggest(h->a);
	while (!stack_sorted(h->a))
	{
		if (h->a->i > h->a->next->i && h->a->i != b)
			swap_stack(h, 0);
		if (!stack_sorted(h->a))
			rotate_stack(h, 0);
	}
	return (h);
}

int		find_int(t_stack *a, int s)
{
	int		rot;
	t_stack	*aa;

	rot = 0;
	aa = a;
	while (a->i != s)
	{
		++rot;
		a = a->next;
	}
	if (rot <= stack_len(aa) / 2)
		return (1);
	return (0);
}

t_hub	*stack_rot_to_last(t_hub *h)
{
	int b;

	b = stack_biggest(h->a);
	if (find_int(h->a, b))
	{
		while (stack_get_last(h->a) != b)
			rotate_stack(h, 0);
	}
	else
	{
		while (stack_get_last(h->a) != b)
			reverse_stack(h, 0);
	}
	return (h);
}

t_hub	*fin_rot(t_hub *h)
{
	int low;

	low = stack_lowest(h->a);
	if (low == h->a->i)
		return (h);
	if (find_int(h->a, low))
	{
		while (h->a->i != low)
			rotate_stack(h, 0);
	}
	else
	{
		while (h->a->i != low)
			reverse_stack(h, 0);
	}
	return (h);
}

int		all_low_that(t_stack *a, int t)
{
	while (a)
	{
		if (a->i > t)
			return (0);
		a = a->next;
	}
	return (1);
}
