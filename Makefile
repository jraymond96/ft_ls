# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 17:03:12 by jraymond          #+#    #+#              #
#    Updated: 2018/05/09 04:54:43 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = handle_mode.c \
	   handle_time.c \
	   handle_uid_gid.c \
	   main.c \
	   del_btdel.c \
	   ft_print_btree.c \
	   handle_link.c \
	   option_management.c \
	   take_sorting_param.c \
	   small_fonc.c \
	   call_allparam.c \
	   use_stat.c \
	   info_term.c \
	   select_insertree.c \
	   recur_solve.c \
	   take_info_file.c \
	   error.c

#COLORS

_GREEN=\x1b[32m
_RED=\x1b[31m
_END=\x1b[0m

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@make -C lib
		@make -C ft_printf
		@$(CC) $(FLAGS) ./lib/libft.a ./ft_printf/libftprintf.a $(OBJS) -o $(NAME)
		@echo "$(_GREEN)$(NAME) created$(_END)"

%.o : %.c
		@$(CC) $(FLAGS) -o $@ -c $^

clean :
		@make clean -C ./lib
		@make clean -C ./ft_printf
		@rm -rf $(OBJS)
		@echo "$(_RED)clean : $(_GREEN)Done$(_END)"

fclean : clean
		@make fclean -C ./lib
		@make fclean -C ./ft_printf
		@rm -rf $(NAME)
		@echo "$(_RED)fclean : $(_GREEN)Done$(_END)"

re :
	@make fclean
	@make
