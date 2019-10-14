/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:36:31 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/11 17:01:01 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	*read_input(void)
{
	char	*data;
	char	buff[BUFF_SIZE + 1];
	int		bytes;

	data = ft_memalloc(sizeof(char));
	bytes = read(0, buff, BUFF_SIZE);
	buff[bytes] = 0;
	while (bytes)
	{
		data = ft_strrejoin(data, buff);
		bytes = read(0, buff, BUFF_SIZE);
		buff[bytes] = 0;
	}
	return (data);
}

int		check_params(t_hub *h, char *av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'v')
			h->v = 1;
		else if (av[i] == 'c')
			h->c = 1;
		else if (av[i] == 'd')
			h->d = 1;
		else if (av[i] == 't')
			h->t = 1;
		else if (av[i] == ' ')
			return (1);
		else
			return (0);
		++i;
	}
	return (1);
}

char	**make_av(t_hub *h, char **av)
{
	if (!av[1])
		return (NULL);
	if (ft_strchr(av[1], ' '))
		av = ft_strsplit(av[1], ' ');
	else
		av = &av[1];
	if (av[0] && av[0][0] == '-' && !ft_isdigit(av[0][1]))
	{
		if (!check_params(h, av[0]))
		{
			send_message(h, 2);
			return (NULL);
		}
		if (!av[1])
			return (NULL);
		if (ft_strchr(av[1], ' '))
		{
			av = ft_strsplit(av[1], ' ');
		}
		else
			av = &av[1];
	}
	return (av);
}

int		do_ex_commands_and_debug(t_hub *h)
{
	int		count;
	char	*data;

	data = read_input();
	if ((count = stack_manipulate_simple(h, data)) == -1)
		exit(send_message(h, 4));
	if (h->v || h->d || h->t)
		print_both_c(h, 0);
	if (h->c)
		ft_printf("[{tyellow}WARN{r}]: {l}{b}Operations:{r} %i\n", count);
	if (stack_sorted(h->a) && !h->b && h->a->i == stack_lowest(h->a))
		send_message(h, 1);
	else
		send_message(h, 0);
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_hub	*h;

	h = (t_hub *)ft_memalloc(sizeof(t_hub));
	if (!(av = make_av(h, av)))
		exit(1);
	ac = array_len(av);
	send_message(h, -1);
	if (ac > 0)
		h->a = make_struct(ac, av);
	else
		exit(1);
	if (!h->a)
		exit(send_message(h, 3));
	if (h->v || h->d || h->t)
	{
		print_both_c(h, 0);
		if (stack_sorted(h->a) && !h->b && h->a->i == stack_lowest(h->a))
			send_message(h, 1);
		else
			send_message(h, 0);
	}
	return (do_ex_commands_and_debug(h));
}
