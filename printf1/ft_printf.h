/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 10:28:31 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:53:59 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_LONG_LONG 9223372036854775807

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_params
{
	char		*specificator;
	int			length;
	char 		zero;
	char		minus;
	int 		width;
	int 		dote;
	int 		accuracy;
	char 		type;
}				t_params;


int				ft_printf(const char *format, ...);
int				parser(const char *format, va_list *ap, t_params *params, int *len_spec, int *len_cicle);
char			*ft_get_spec(char *str);
int				ft_get_value(va_list *ap, t_params *params);

int				ft_print_c(va_list *ap, t_params *params);
int				ft_print_s(char *input, t_params *params);
int				ft_print_p(t_params *params, va_list *ap);
int 			ft_print_d_i(int input, t_params *params);

int				ft_print_u(t_params *params, va_list *ap);
int				ft_print_x(t_params *params, va_list *ap);

int				ft_putchar(char c);
void			ft_putnbr(int n, t_params *params);
void			ft_putunbr(unsigned int digit, t_params *params);
void			ft_putchar_len(char c, int len, t_params *params);
void			ft_putnchar(char c, int len, t_params *params);

int				ft_strlen(char *str);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
char			*ft_itoa(int n);
int				len_u_digit(size_t digit, char type);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);



#endif
