/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/07 20:48:35 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H

# define PS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

# define MIN_STACK	2
# define BUFF_SIZE	16

typedef struct	s_hub
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				c;
	int				v;
	int				d;
	int				t;
	int				count;
	char			*out;
}				t_hub;

typedef struct	s_stack
{
	int				i;
	struct s_stack	*next;
}				t_stack;

int				ft_printf(const char *str, ...);
char			*ft_strrejoin(char const *s1, char const *s2);
char			*ft_strreplace(char *str, const char *old, const char *new);
char			**ft_strsplit(char const *s, char c);
void			*ft_memmove(void *dest, const void *source, size_t n);
size_t			ft_strclen(char const *str, char c);
char			*ft_strnew(size_t size);
int				ft_count_words(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);

void			debug_print(t_hub *h, int mode, int mes);
void			print_both_c(t_hub *h, int mode);
void			print_one_cyan(t_stack *a, int l);
void			print_one_yellow(t_stack *a, int l);

t_stack			*stack_swap(t_stack *a);
t_stack			*stack_rotate(t_stack *a);
t_stack			*stack_reverse(t_stack *a);
void			stack_push(t_hub *h, int d);
t_hub			*fin_rot(t_hub *h);
int				array_len(char **arr);

int				stack_lowest(t_stack *a);
int				stack_biggest(t_stack *a);
int				stack_len(t_stack *a);
int				stack_sorted(t_stack *s);
int				r_stack_sorted(t_stack *s);
t_stack			*make_struct(int ac, char **av);
int				part_center(t_stack *a, int len);
int				stack_center(t_stack *a);
int				stack_r_delimeted(t_stack *a, int factor);
int				stack_delimeted(t_stack *a, int factor);
int				stack_get_last(t_stack *a);
void			stack_destroy(t_stack *a);
t_hub			*stack_rot_to_last(t_hub *h);
t_hub			*bubble_sort(t_hub *h);

int				dia_biggest(t_stack *a, int min, int max);
int				dia_lowest(t_stack *a, int min, int max);
int				dia_len(t_stack *a, int min, int max);
int				dia_sorted(t_stack *a, int min, int max);
int				dia_center(t_stack *a, int min, int max);
t_hub			*dia_bubble_sort(t_hub *h, int max);
void			dia_start(t_hub *h, int min, int max);
void			dia_f_a(t_hub *h, int min, int max);
int				find_low(t_stack *a, int s);
void			add_bigger(t_hub *h, int half);
void			dia_return(t_hub *h, int max);
void			dia_prereturn(t_hub *h, int min, int max);
int				all_low_that(t_stack *a, int t);

void			swap_stack(t_hub *h, int a);
void			rotate_stack(t_hub *h, int a);
void			reverse_stack(t_hub *h, int a);
void			push_stack(t_hub *h, int d);

int				stack_manipulate_simple(t_hub *h, char *data);
int				int_checker(char *str);

int				send_message(t_hub *h, int id);
int				hub_len(t_hub *h);
int				allow_this(t_stack *a, char *c);
void			debug_msg(t_hub *h, char **arr, int i, int t);

#endif
