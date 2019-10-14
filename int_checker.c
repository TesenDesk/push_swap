/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:29:53 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/01 18:45:07 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_checker(char *str)
{
	int	curr;
	int	i;

	curr = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
			continue;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (curr != (curr * 10 + str[i] - '0') / 10)
			{
				if (str[i] != '8' || str[0] != '-' || str[i + 1] ||
						curr != 214748364)
					return (0);
			}
			curr = curr * 10 + str[i] - '0';
		}
		else
			return (0);
	}
	return (1);
}
