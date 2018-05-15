# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 08:00:10 by jraymond          #+#    #+#              #
#    Updated: 2018/05/15 01:36:58 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRCS = 	main.c \
		get_param.c \
		ptr_btree.c \
		select_insertree.c \
		call_lstat.c \
		ptr_fonc_print.c \
		handle_mode.c \
		handle_time.c \
		handle_link.c \
		handle_uid_gid.c \
		call_files.c \
		del_btdel.c \
		take_info_file.c \
		ft_print_btree.c \
		small_fonc.c \
		recur_solve.c \
		info_term.c \
		error.c

#COLORS

_GREEN=\x1b[32m
_RED=\x1b[31m
_END=\x1b[0m

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.PHONY : all fclean clean re

$(NAME) : $(OBJS)
	@make -C ft_printf
	@make -C lib
	@$(CC) $(FLAGS) ./lib/libft.a ./ft_printf/libftprintf.a $(OBJS) -o $(NAME)
	@echo "$(_GREEN)$(NAME) created$(_END)"

%.o : %.c
		@$(CC) $(FLAGS) -o $@ -c $^

clean :
		@make clean -C lib
		@make clean -C ft_printf
		@rm -rf $(OBJS)
		@echo "$(_RED)clean : $(_GREEN)Done$(_END)"

fclean : clean
		@make fclean -C lib
		@make fclean -C ft_printf
		@rm -rf $(NAME)
		@echo "$(_RED)fclean : $(_GREEN)Done$(_END)"

re :
	@make fclean
	@make
