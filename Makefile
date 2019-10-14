# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 15:17:26 by jjerde            #+#    #+#              #
#    Updated: 2019/10/13 16:11:51 by jjerde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean liba re debug delfile checkdir

GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)$(PNAME)$(RST)]:
#hello
PNAME =		push_swap
CNAME =		checker
WORKDIR =	./
HEADERDIR =	$(WORKDIR)includes/
HEADER =	$(HEADERDIR)ps.h
ODIR =		$(WORKDIR)objects/
LIBDIR =	$(WORKDIR)libft/
LIB =		$(LIBDIR)libft.a
SRC =		debug.c dia2.c diapasone.c encode.c stack_staff2.c stack_staff.c \
			staff.c standart.c std_redirect.c dia.c debug_print.c \
			stack_manipulate.c int_checker.c
LIBFLAG =	-L $(LIBDIR) -lft
FLAGS =		-Wall -Wextra -Werror
OBJ =		$(addprefix $(ODIR), $(SRC:.c=.o))

#%.o: $(WORKDIR)/%.c
#		gcc -c $(FLAGS) -o $@ $^ -I$(HEADERDIR)

$(ODIR)%.o: $(WORKDIR)%.c $(HEADER)
		@printf "%-95c\r$(PREFIX)" ' '
		@printf "Compiling file:\t %-25s=>\t%-25s\r" "$<" "$@"
		@gcc -c $(FLAGS) -o $@ $< -I$(HEADERDIR)

all: liba checkdir $(PNAME) $(CNAME) $(HEADER)
		@echo "$(PREFIX) ✅  $(GREEN)All files up-to-date or rebuilded.$(RST)"

checkdir:
		@mkdir -p $(ODIR)

liba:
		@echo "$(PREFIX) \033[1mUpdating libft...\033[0m"
		@make -C libft/

$(PNAME): $(LIB) $(OBJ) $(PNAME).c $(HEADER)
		@printf "%-95c\r$(PREFIX) Building $(PNAME)...\n" ' '
		@gcc -c $(FLAGS) $(PNAME).c -o $(ODIR)$(PNAME).o -I$(HEADERDIR)
		@gcc $(FLAGS) -o $(PNAME) $(OBJ) $(ODIR)$(PNAME).o $(LIBFLAG)

$(CNAME): $(LIB) $(OBJ) $(CNAME).c $(HEADER)
		@printf "%-95c\r$(PREFIX) Building $(CNAME)...\n" ' '
		@gcc -c $(FLAGS) $(CNAME).c -o $(ODIR)$(CNAME).o -I$(HEADERDIR)
		@gcc $(FLAGS) -o $(CNAME) $(OBJ) $(ODIR)$(CNAME).o $(LIBFLAG)

clean: deljunk
		@echo "$(PREFIX) ♻️  $(RED)Removing obj-files\033[0m"
		@make -C libft clean

delfile:
		@echo "$(PREFIX) ♻️  $(RED)Removing binary files...\033[0m"
		@/bin/rm -f $(CNAME) $(PNAME)

fclean: clean delfile
		@make -C libft/ fclean

deljunk:
		@/bin/rm -f $(OBJ) $(ODIR)$(CNAME).o $(ODIR)$(PNAME).o

re: fclean
		@make all

debug: delfile
	gcc -g -c $(FLAGS) $(CNAME).c -o $(ODIR)$(CNAME).o -I$(HEADERDIR)
	gcc $(FLAGS) -o $(CNAME) $(OBJ) $(ODIR)$(CNAME).o $(LIBFLAG)
	gcc -g -c $(FLAGS) $(PNAME).c -o $(ODIR)$(PNAME).o -I$(HEADERDIR)
	gcc $(FLAGS) -o $(PNAME) $(OBJ) $(ODIR)$(PNAME).o $(LIBFLAG)
