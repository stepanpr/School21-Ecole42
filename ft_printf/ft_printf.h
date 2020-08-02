/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 10:28:31 by emabel            #+#    #+#             */
/*   Updated: 2020/08/02 00:15:19 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_params
{
	char		minus;
	char		zero;
	int			width;
	int			accuracy;
	int			acc;
	char		type;
	int			count;
	int			hash;
	int			space;
	int			plus;

}				t_params;

int				ft_printf(const char *format, ...);
int				ft_parser(char **string, t_params *params, va_list *ap);
int				parser_type(t_params *params, va_list *ap);
int				ft_print_c(t_params *params, char c);
int				ft_print_d_i(t_params *params, va_list *ap);
int				ft_print_s(t_params *par, va_list *ap);
int				ft_print_p(t_params *params, va_list *ap);
int				ft_print_u(t_params *params, va_list *ap);
int				ft_print_x(t_params *params, va_list *ap);
void			ft_putchar_len(char c, int len, t_params *params);
void			ft_putunbr(unsigned int digit, t_params *params);
void			ft_putnbr(int n, t_params *params);
int				ft_putchar(char c);
int				print_max_digit(t_params *params, int digit);
char			*ft_strchr_print_c(const char *s, int c, t_params *params);
int				ft_strlen(char *str);
int				len_u_digit(size_t digit, char type);
int				len_digit(int digit);
int				ft_isdigit(int c);

#endif
