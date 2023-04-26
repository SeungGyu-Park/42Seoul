/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 01:49:05 by seunggpa          #+#    #+#             */
/*   Updated: 2022/05/09 03:27:23 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>

int				ft_printf(const char *format, ...);
unsigned int	ft_put_specifier(char spec, va_list ap);
unsigned int	ft_putchar(char ch);
unsigned int	ft_putnbr(int nb);
unsigned int	ft_putstr(char *str);
unsigned int	ft_putunsigned(unsigned int n);
unsigned int	ft_puthex(unsigned long num, int flag);
#endif