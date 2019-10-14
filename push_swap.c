/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:30:02 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 23:15:38 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		do_sorting_and_debug(int ac, char **av)
{
	t_hub	*h;

	if (!av)
		exit(1);
	if (!(h = (t_hub *)ft_memalloc(sizeof(t_hub))))
		exit(1);
	h->out = (char *)ft_memalloc(sizeof(char));
	if (ac > 0)
		h->a = make_struct(ac, av);
	else
		exit(0);
	if (!h->a)
		exit(send_message(h, 4));
	if (!stack_sorted(h->a))
		dia_start(h, stack_lowest(h->a) - 1, stack_biggest(h->a) + 1);
	fin_rot(h);
	if (h->out[0])
		ft_printf("%s\n", h->out);
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	char	**aw;

	if (ac == 2)
	{
		ac = 0;
		aw = ft_strsplit(av[1], ' ');
		while (aw[ac])
			++ac;
	}
	else
	{
		aw = &av[1];
		--ac;
	}
	return (do_sorting_and_debug(ac, aw));
}
