# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 15:17:26 by jjerde            #+#    #+#              #
#    Updated: 2019/10/13 16:16:10 by jjerde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

PREFIX =	[\033[1;36mlibft\033[0m]:

NAME =		libft.a
SRC =		ft_flag_g.c ft_litoa.c ft_minus.c ft_strchr.c ft_strmap.c \
			ft_strstr.c check_hub.c ft_flag_i.c ft_lstadd.c \
			ft_strclen.c ft_strmapi.c ft_strsub.c checker.c ft_flag_o_u_x.c \
			ft_lstdel.c ft_proverka.c ft_strclr.c ft_strncat.c ft_strtrim.c \
			colors.c ft_flag_p.c ft_lstdelone.c ft_putchar.c ft_strcmp.c \
			ft_strncmp.c ft_tolower.c flag_checker.c ft_i_5.c ft_lstiter.c \
			ft_putchar_fd.c ft_strcpy.c ft_strncpy.c ft_toupper.c \
			flag_g_free.c ft_isalnum.c ft_lstmap.c ft_putendl.c ft_strdel.c \
			ft_strnequ.c ft_uitoa.c ft_atoi.c ft_isalpha.c ft_lstnew.c \
			ft_putendl_fd.c ft_strdup.c ft_strnew.c ft_width.c ft_bzero.c \
			ft_isascii.c ft_memalloc.c ft_putnbr.c ft_strequ.c ft_strnstr.c \
			 ft_chacc.c ft_isdigit.c ft_memccpy.c ft_putnbr_fd.c \
			ft_striter.c ft_strrchr.c main.c ft_clearone.c ft_isprint.c \
			ft_memchr.c ft_putstr.c ft_striteri.c ft_strrejoin.c \
			mod_redirect.c ft_count_words.c ft_isspace.c ft_memcmp.c \
			ft_putstr_fd.c ft_strjoin.c ft_strrejoinre.c modificators.c \
			ft_flag_e.c ft_isxdigit.c ft_memcpy.c ft_sqrt.c ft_strjoinfree.c \
			ft_strrejoinren.c printf_depleted.c ft_flag_e_2.c ft_itoa.c \
			ft_memdel.c ft_sstrlen.c ft_strjoinre.c ft_strreplchar.c \
			redirect_target_get.c ft_flag_f.c ft_list_last.c ft_memmove.c \
			ft_sswap.c ft_strlcat.c ft_strsearch.c redirect_target_icsf_.c \
			ft_flag_f_2.c ft_list_size.c ft_memset.c ft_strcat.c ft_strlen.c \
			ft_strsplit.c
HEADER =	ft_printf.h
FLAGS =		-Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

%.o: %.c
		@printf "%-95c\r$(PREFIX) " ' '
		@printf "Compiling file:\t %-25s=>\t%-25s\r" "$^" "$@"
		@gcc -c $(FLAGS) $^ -I$(HEADER)

all: $(NAME)
		@echo "$(PREFIX) ✅  \033[1;32mDone\033[0m"

$(NAME): $(OBJ) $(SRC) $(HEADER)
		@printf "" ' '
		@printf "%-95c\r$(PREFIX) \033[1;32mAll files accepted.\n\033[0m" ' '
		@printf "$(PREFIX) Making $(NAME)...\n"
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
clean:
		@echo "$(PREFIX) ♻️  \033[1;31mRemoving obj-files...\033[0m"
		@/bin/rm -f $(OBJ)
fclean: clean
		@echo "$(PREFIX) ♻️  \033[1;31mRemoving $(NAME)...\033[0m"
		@/bin/rm -f $(NAME)
re: fclean
		@make all
