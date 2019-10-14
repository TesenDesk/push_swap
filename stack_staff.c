/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_staff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:03:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 21:04:07 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		stack_lowest(t_stack *a)
{
	int		i;

	i = a->i;
	while (a)
	{
		if (a->i < i)
			i = a->i;
		a = a->next;
	}
	return (i);
}

int		stack_biggest(t_stack *a)
{
	int		i;

	i = a->i;
	while (a)
	{
		if (a->i > i)
			i = a->i;
		a = a->next;
	}
	return (i);
}

int		stack_len(t_stack *a)
{
	int		i;

	if (!a)
		return (0);
	i = 1;
	while (a->next)
	{
		++i;
		a = a->next;
	}
	return (i);
}

int		stack_sorted(t_stack *a)
{
	int b;
	int c;
	int l;
	int f;

	b = stack_biggest(a);
	l = stack_lowest(a);
	f = a->i;
	while (a->next)
	{
		c = a->i;
		a = a->next;
		if (c == b)
		{
			if (a->i != l)
				return (0);
		}
		else if (c > a->i)
			return (0);
	}
	if (a->i != b && a->i > f)
		return (0);
	return (1);
}

int		r_stack_sorted(t_stack *s)
{
	int n;

	while (s)
	{
		n = s->i;
		s = s->next;
		if (s && n <= s->i)
			return (0);
	}
	return (1);
}
