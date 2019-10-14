/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diapasone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:18:49 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/01 16:27:26 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	dia_lowest(t_stack *a, int min, int max)
{
	int lowest;

	if (!a)
		return (-9999);
	lowest = a->i;
	while (a)
	{
		if (a->i > min && a->i < max)
		{
			if (a->i < lowest)
				lowest = a->i;
		}
		a = a->next;
	}
	return (lowest);
}

int	dia_biggest(t_stack *a, int min, int max)
{
	int biggest;

	if (!a)
		return (-9999);
	biggest = a->i;
	while (a)
	{
		if (a->i > min && a->i < max)
		{
			if (a->i > biggest)
				biggest = a->i;
		}
		a = a->next;
	}
	return (biggest);
}

int	dia_len(t_stack *a, int min, int max)
{
	int	len;

	len = 0;
	while (a)
	{
		if (a->i > min && a->i < max)
			++len;
		a = a->next;
	}
	return (len);
}

int	dia_sorted(t_stack *a, int min, int max)
{
	int	current;
	int	b;
	int	l;

	b = dia_biggest(a, min, max);
	l = dia_lowest(a, min, max);
	while (a && a->next && a->i < max && a->i > min)
	{
		current = a->i;
		a = a->next;
		if (current == b)
		{
			if (a->i != l)
				return (0);
		}
		else if (current > a->i)
			return (0);
	}
	return (1);
}

int	dia_center(t_stack *a, int min, int max)
{
	long int	tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (a)
	{
		if (a->i < max && a->i > min)
		{
			tmp += a->i;
			++i;
		}
		a = a->next;
	}
	if (!i)
		return (-9999);
	return (tmp / i);
}
