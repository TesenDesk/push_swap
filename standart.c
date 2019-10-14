/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:53:34 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 21:06:14 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*stack_swap(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (a && a->next)
	{
		tmp = a->next;
		a->next = a->next->next;
		tmp->next = a;
	}
	return (tmp);
}

t_stack	*stack_rotate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*c;

	if (!a || !a->next)
		return (a);
	tmp = a;
	a = a->next;
	c = a;
	while (c->next)
		c = c->next;
	tmp->next = NULL;
	c->next = tmp;
	return (a);
}

t_stack	*stack_reverse(t_stack *a)
{
	t_stack	*pre;
	t_stack	*c;

	if (!a || !a->next)
		return (a);
	c = a;
	while (c->next)
	{
		pre = c;
		c = c->next;
	}
	pre->next = NULL;
	c->next = a;
	a = c;
	return (a);
}

void	stack_push(t_hub *h, int d)
{
	t_stack	*tmp;

	if (d > 0 && h->a)
	{
		tmp = h->a;
		h->a = h->a->next;
		tmp->next = h->b;
		h->b = tmp;
	}
	else if (d < 0 && h->b)
	{
		tmp = h->b;
		h->b = h->b->next;
		tmp->next = h->a;
		h->a = tmp;
	}
}
