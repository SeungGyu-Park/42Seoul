/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 01:48:52 by seunggpa          #+#    #+#             */
/*   Updated: 2022/05/09 03:40:22 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_specifier(char spec, va_list ap)
{
	unsigned int	len;

	len = 0;
	if (spec == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthex(va_arg(ap, unsigned long), 1);
	}
	else if (spec == 'd' || spec == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		len += ft_putunsigned(va_arg(ap, unsigned int));
	else if (spec == 'x')
		len += ft_puthex(va_arg(ap, unsigned int), 1);
	else if (spec == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), 0);
	else if (spec == '%')
		len += ft_putchar(spec);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_put_specifier(*format, ap);
		}
		else if (*format != '%')
			len += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
