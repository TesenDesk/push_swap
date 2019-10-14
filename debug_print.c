/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:07:42 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 17:54:08 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	debug_msg(t_hub *h, char **arr, int i, int t)
{
	if (h->d)
	{
		if (!t)
			ft_printf("Execute command: %s. Result:\n", arr[i]);
		else
			print_both_c(h, 1);
	}
	else if (h->v)
	{
		if (t)
		{
			if (h->count > 3)
			{
				print_both_c(h, 1);
				h->count = 0;
			}
			else
				h->count += 1;
		}
	}
}

int		hub_len(t_hub *h)
{
	int a;
	int b;

	a = stack_len(h->a);
	b = stack_len(h->b);
	if (b > a)
		a = b;
	return (a);
}

void	generate_messages(t_hub *h)
{
	if (h->c)
		ft_printf("[{tyellow}{b}WARN{r}]: Counter enabled!\n");
	if (h->v)
		ft_printf("[{tyellow}{b}WARN{r}]: Visualization enabled!\n");
	if (h->d)
		ft_printf("[{tyellow}{b}WARN{r}]: Debug mode enabled!\n");
	if (h->t)
		ft_printf("[{tyellow}{b}WARN{r}]: Tables-only mode enabled!\n");
}

void	std_msg(int id)
{
	if (!id)
		write(1, "KO\n", 3);
	else if (id == 1)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}

int		send_message(t_hub *h, int id)
{
	if (id == -1)
		generate_messages(h);
	else if (h->t || h->v || h->d)
	{
		if (id == 0)
			ft_printf("[{tcyan}{b}INFO{r}]: {tred}KO{r}\n");
		else if (id == 1)
			ft_printf("[{tcyan}{b}INFO{r}]: {tgreen}OK{r}\n");
	}
	else if (h->v || h->d)
	{
		if (id == 2)
			ft_printf("[{tred}{b}ERROR{r}]: Not valid flags!\n");
		else if (id == 3)
			ft_printf("[{tred}{b}ERROR{r}]: Wrong numbers!\n");
		else if (id == 4)
			ft_printf("[{tred}{b}ERROR{r}]: Command not found.\n");
		else if (id == 5)
			ft_printf("[{tred}{b}ERROR{r}]: No input data detected.\n");
		else if (id == 6)
			ft_printf("[{tmagenta}{b}DEBUG{r}]: Debugger message:\n");
	}
	if (id < 5 && id != -1)
		std_msg(id);
	return (1);
}
