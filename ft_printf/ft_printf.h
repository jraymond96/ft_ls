/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:50:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/05/09 04:32:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wctype.h>
# include <locale.h>

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 128

/*
**--------------------------------MASK-FLAGS------------------------------------
*/

# define ZERO (1 << 0)
# define SHARP (1 << 1)
# define MINUS (1 << 2)
# define SPACE (1 << 3)
# define MORE (1 << 4)
# define PRECI (1 << 5)
# define BINARY (1 << i)

/*
**--------------------------------MASK-SIZE-------------------------------------
*/

# define HH (1 << 0)
# define H (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define Z (1 << 4)
# define J (1 << 5)

/*
**-------------------------------STRUCTURES-------------------------------------
*/

typedef struct	s_overflow
{
	int			i;
	char		*data_b;
	int			flag;
}				t_overflow;

typedef struct	s_color
{
	char		*name;
	char		code;
}				t_color;

typedef struct	s_printf
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			length;
	int			i_buff;
	int			no_type;
	char		flags;
	int			width;
	int			precision;
	int			save;
	char		type;
	char		size;
}				t_printf;

typedef	struct	s_nbcaddpw
{
	int			preci;
	int			width;
}				t_nbcaddpw;
/*
**---------------------------------FONC-PRINTF----------------------------------
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_read_format(const char *format, va_list ap, t_printf *elem);
char			ft_char_is_type(char c);
void			ft_argis_str(va_list ap, t_printf *elem);
void			ft_init_struct(t_printf *elem);
void			ft_deal_flags(t_printf *elem, const char *format);
int				ft_deal_precision(t_printf *elem, const char *format,
					va_list ap);
int				ft_deal_width(t_printf *elem, const char *format, va_list ap);
int				ft_deal_size(t_printf *elem, const char *format);
int				ft_handle_param(t_printf *elem, va_list ap);
int				ft_handle_unicode(t_printf *elem, va_list ap);
void			unicode_to_str(wchar_t unicode, char *str);
int				ft_howchar_add(t_printf *elem, int len);
void			ft_addstr_no_minus(t_printf *elem, char *str, int nb_c_add);
void			ft_addstr_with_minus(t_printf *elem, char *str, int nb_c_add);
void			ft_handle_overflow(t_printf *elem, void *data, int nb, int spe);
int				ft_param_char(t_printf *elem, va_list ap);
int				ft_unicodelen(wchar_t unicode);
int				ft_param_decimal(t_printf *elem, va_list ap);
intmax_t		ft_handle_size(t_printf *elem, va_list ap);
void			ft_padding_numbnull(t_printf *elem, t_nbcaddpw *nbca);
uintmax_t		ft_handle_usize(t_printf *elem, va_list ap);
void			nb_c_add_pw(t_nbcaddpw *nbca, t_printf *elem, int intl,
					char *numb);
void			ft_handle_sign(t_printf *elem, t_nbcaddpw *nbca, char *numb);
void			ft_padding_numbposi(t_printf *elem, t_nbcaddpw *nbca,
					char *numb);
int				ft_param_unsigned(t_printf *elem, va_list ap);
int				ft_uilen(uintmax_t arg);
int				ft_param_percent(t_printf *elem);
uintmax_t		ft_handle_uoctsize(t_printf *elem, va_list ap);
int				ft_param_octal(t_printf *elem, va_list ap);
int				ft_padding_octnull(t_printf *elem, t_nbcaddpw *nbca);
uintmax_t		ft_handle_uhexasize(t_printf *elem, va_list ap);
int				ft_param_hexa(t_printf *elem, va_list ap);
int				ft_paddoct_null(t_printf *elem, t_nbcaddpw *nbca);
int				ft_param_address(t_printf *elem, va_list ap);
int				ft_handle_notype(t_printf *elem, const char *format);
void			ft_param_color(t_printf *elem, const char *format);
int				ft_param_binary(t_printf *elem, va_list ap);
int				ft_print_binary(t_printf *elem, long long binary, int size);
int				ft_print_ubinary(t_printf *elem, unsigned long long binary,
					int size);
void			ft_param_n(t_printf *elem, va_list ap);
void			ft_posi_no_minus(t_printf *elem, t_nbcaddpw *nbca, char *numb);
void			ft_neg_no_minus(t_printf *elem, t_nbcaddpw *nbca, char *numb);
/*
**---------------------------------FONC-LIB-------------------------------------
*/
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_abs(int nb);
long long		ft_llabs(long long nb);
char			*ft_ulltoa_base(unsigned long long nb, int base);
char			*ft_strcchr(const char *s, int c, char stop);
char			*ft_lltoa(long long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
int				ilen(intmax_t arg);
char			*ft_strcpy(char *dest, const char *src);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
