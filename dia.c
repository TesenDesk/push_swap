/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:11:53 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 21:10:57 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	add_bigger(t_hub *h, int half)
{
	while (!all_low_that(h->b, half))
	{
		if (h->b->i > half)
			push_stack(h, -1);
		else
			rotate_stack(h, 1);
	}
}

void	drop_lowest(t_hub *h, int half)
{
	while (!stack_r_delimeted(h->a, half))
	{
		if (h->a->i <= half)
			push_stack(h, 1);
		else
			rotate_stack(h, 0);
	}
}

void	dia_f_a(t_hub *h, int min, int max)
{
	int half;

	stack_rot_to_last(h);
	if (dia_len(h->a, min, max) > MIN_STACK && !stack_sorted(h->a))
	{
		half = dia_center(h->a, min, max);
		drop_lowest(h, half);
		dia_f_a(h, half, max);
		dia_return(h, min);
		dia_f_a(h, min, half + 1);
	}
	else if (!stack_sorted(h->a))
	{
		if (stack_len(h->a) > MIN_STACK)
			dia_bubble_sort(h, max);
		else
			bubble_sort(h);
	}
	fin_rot(h);
}

void	dia_start(t_hub *h, int min, int max)
{
	int half;

	if (stack_len(h->a) > MIN_STACK + 1)
	{
		half = stack_center(h->a);
		drop_lowest(h, half);
		dia_f_a(h, half, max);
		fin_rot(h);
		dia_prereturn(h, min, half + 1);
	}
	else
		bubble_sort(h);
}
