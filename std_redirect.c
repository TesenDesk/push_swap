/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:22:52 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 21:06:35 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap_stack(t_hub *h, int a)
{
	if (a)
	{
		h->out = ft_strrejoin(h->out, "sb\n");
		h->b = stack_swap(h->b);
	}
	else
	{
		h->out = ft_strrejoin(h->out, "sa\n");
		h->a = stack_swap(h->a);
	}
}

void	rotate_stack(t_hub *h, int a)
{
	if (a)
	{
		h->out = ft_strrejoin(h->out, "rb\n");
		h->b = stack_rotate(h->b);
	}
	else
	{
		h->out = ft_strrejoin(h->out, "ra\n");
		h->a = stack_rotate(h->a);
	}
}

void	reverse_stack(t_hub *h, int a)
{
	if (a)
	{
		h->out = ft_strrejoin(h->out, "rrb\n");
		h->b = stack_reverse(h->b);
	}
	else
	{
		h->out = ft_strrejoin(h->out, "rra\n");
		h->a = stack_reverse(h->a);
	}
}

void	push_stack(t_hub *h, int d)
{
	if (d > 0)
		h->out = ft_strrejoin(h->out, "pb\n");
	else if (d < 0)
		h->out = ft_strrejoin(h->out, "pa\n");
	stack_push(h, d);
}
