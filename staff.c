/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:10:30 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/01 17:10:09 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		only_numbers(char *c)
{
	int		i;

	i = 0;
	if (c[0] == '-')
		i = 1;
	while (c[i])
	{
		if (ft_isdigit(c[i]))
			i++;
		else
			return (0);
	}
	return (i);
}

int		allow_this(t_stack *a, char *c)
{
	int		i;

	if (!c[0] || !only_numbers(c))
		return (0);
	i = ft_atoi(c);
	while (a)
	{
		if (a->i == i)
		{
			if (i || a->next)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

int		stack_get_last(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->i);
}

int		array_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}
