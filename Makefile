# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 17:03:12 by jraymond          #+#    #+#              #
#    Updated: 2018/04/25 09:17:47 by jraymond         ###   ########.fr        #
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
	   ft_strofpoint.c \
	   call_allparam.c \
	   use_stat.c \
	   info_term.c

#COLORS

_GREEN=\x1b[32m
_RED=\x1b[31m
_END=\x1b[0m

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@make -C ./lib
		@$(CC) $(FLAGS) ./lib/libft.a libftprintf.a $(OBJS) -o $(NAME)
		@echo "$(_GREEN)$(NAME) created$(_END)"

%.o : %.c
		@$(CC) $(FLAGS) -o $@ -c $^

clean :
		@make clean -C ./lib
		@rm -rf $(OBJS)
		@echo "$(_RED)clean : $(_GREEN)Done$(_END)"

fclean : clean
		@make fclean -C ./lib
		@rm -rf $(NAME)
		@echo "$(_RED)fclean : $(_GREEN)Done$(_END)"

re :
	@make fclean
	@make
