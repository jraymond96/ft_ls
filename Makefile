# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/13 03:17:48 by jraymond          #+#    #+#              #
#    Updated: 2018/05/13 08:03:00 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

all : libprintf
	@(gcc $(FLAGS)	mainbis.c \
					get_param.c \
					ptr_btree.c \
					select_insertree.c \
					lib/libft.a \
					call_lstat.c \
					ft_printf/libftprintf.a \
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
					error.c)
	@echo "\x1b[32ma.out -> created\x1b[0m"

libprintf :
	@make -C ft_printf
	@make -C lib

clean :	
	@make clean -C ft_printf
	@make clean -C lib

fclean : clean
	@make fclean -C ft_printf
	@make fclean -C lib
	@rm -rf a.out
