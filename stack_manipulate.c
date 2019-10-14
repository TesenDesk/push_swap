/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:15:59 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 23:29:37 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		clear_stack_manipulation_data(char **arr, int a)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = 0;
	return (a);
}

int		stack_manipulate_deep(t_hub *h, char **arr, int i)
{
	if (!ft_strcmp(arr[i], "pa"))
		stack_push(h, -1);
	else if (!ft_strcmp(arr[i], "pb"))
		stack_push(h, 1);
	else if (!ft_strcmp(arr[i], "ss"))
	{
		h->a = stack_swap(h->a);
		h->b = stack_swap(h->b);
	}
	else if (!ft_strcmp(arr[i], "rr"))
	{
		h->a = stack_rotate(h->a);
		h->b = stack_rotate(h->b);
	}
	else if (!ft_strcmp(arr[i], "rrr"))
	{
		h->a = stack_reverse(h->a);
		h->b = stack_reverse(h->b);
	}
	else
		return (0);
	return (1);
}

int		stack_manipulate_simple(t_hub *h, char *data)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(data, '\n');
	i = -1;
	while (arr[++i])
	{
		debug_msg(h, arr, i, 0);
		if (!ft_strcmp(arr[i], "ra"))
			h->a = stack_rotate(h->a);
		else if (!ft_strcmp(arr[i], "rb"))
			h->b = stack_rotate(h->b);
		else if (!ft_strcmp(arr[i], "rra"))
			h->a = stack_reverse(h->a);
		else if (!ft_strcmp(arr[i], "rrb"))
			h->b = stack_reverse(h->b);
		else if (!ft_strcmp(arr[i], "sa"))
			h->a = stack_swap(h->a);
		else if (!ft_strcmp(arr[i], "sb"))
			h->b = stack_swap(h->b);
		else if (!stack_manipulate_deep(h, arr, i))
			return (-1);
		debug_msg(h, arr, i, 1);
	}
	return (clear_stack_manipulation_data(arr, i));
}
