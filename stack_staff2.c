/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_staff2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:04:36 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/01 17:48:24 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	stack_destroy(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	a = NULL;
}

t_stack	*make_struct(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	t_stack	*current;

	i = -1;
	stack = ft_memalloc(sizeof(t_stack));
	current = stack;
	while (++i < ac)
	{
		if (!(allow_this(stack, av[i]) && int_checker(av[i])))
		{
			stack_destroy(stack);
			return (NULL);
		}
		if (i + 1 < ac)
			current->next = ft_memalloc(sizeof(t_stack));
		current->i = ft_atoi(av[i]);
		current = current->next;
	}
	return (stack);
}

int		stack_center(t_stack *a)
{
	long int	i;
	t_stack		*tmp;

	i = 0;
	tmp = a;
	while (a)
	{
		i += a->i;
		a = a->next;
	}
	i = i / stack_len(tmp);
	return ((int)i);
}

int		stack_r_delimeted(t_stack *a, int factor)
{
	while (a)
	{
		if (a->i <= factor)
			return (0);
		a = a->next;
	}
	return (1);
}

int		stack_delimeted(t_stack *a, int factor)
{
	while (a)
	{
		if (a->i > factor)
			return (0);
		a = a->next;
	}
	return (1);
}
