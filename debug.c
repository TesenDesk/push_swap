/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:57:19 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 21:08:35 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	print_line(int num, int mode)
{
	if (mode)
		ft_printf("{tcyan}+");
	else
		ft_printf("{tyellow}+");
	num += 1;
	while (--num > 0)
		write(1, "---+", 4);
	ft_printf("{r}\n");
}

void	print_one_cyan(t_stack *a, int l)
{
	int i;

	i = l;
	print_line(i, 1);
	i += 1;
	ft_printf("{tcyan}|{r}");
	while (--i > 0)
	{
		if (a)
		{
			ft_printf("%3d{tcyan}|{r}", a->i);
			a = a->next;
		}
		else
			ft_printf("   {tcyan}|{r}");
	}
	write(1, "\n", 1);
}

void	print_one_yellow(t_stack *a, int l)
{
	int i;

	i = l;
	print_line(i, 0);
	i += 1;
	ft_printf("{tyellow}|{r}");
	while (--i > 0)
	{
		if (a)
		{
			ft_printf("%3d{tyellow}|{r}", a->i);
			a = a->next;
		}
		else
			ft_printf("   {tyellow}|{r}");
	}
	write(1, "\n", 1);
}

void	print_both_c(t_hub *h, int mode)
{
	int len;

	len = hub_len(h);
	if (mode)
	{
		print_one_cyan(h->a, len);
		print_one_cyan(h->b, len);
	}
	else
	{
		print_one_yellow(h->a, len);
		print_one_yellow(h->b, len);
	}
	print_line(len, mode);
	write(1, "\n", 1);
}

void	debug_print(t_hub *h, int mode, int mes)
{
	if (!mode && !mes)
		return ;
	if (mes)
		ft_printf("\n[{tmagenta}{b}DEBUG{r}]: Debugger message:\n");
	print_both_c(h, mode);
	if (mes)
		system("read -s -n 1");
}
