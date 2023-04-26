/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 02:32:02 by seunggpa          #+#    #+#             */
/*   Updated: 2022/05/09 03:44:45 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

unsigned int	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

unsigned int	ft_putnbr(int n)
{
	unsigned int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += (ft_putstr("-214748364"));
		n = 8;
	}
	if (n < 0)
	{
		i += (ft_putchar('-'));
		n = -n;
	}
	if (n > 9)
	{
		i += (ft_putnbr(n / 10));
		i += (ft_putnbr(n % 10));
	}
	else
		i += (ft_putchar(n + 48));
	return (i);
}

unsigned int	ft_putunsigned(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 9)
	{
		i += (ft_putunsigned(n / 10));
		i += (ft_putunsigned(n % 10));
	}
	else
		i += (ft_putchar(n + 48));
	return (i);
}

unsigned int	ft_puthex(unsigned long num, int flag)
{
	unsigned int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_puthex(num / 16, flag);
	}
	if (num % 16 < 10)
	{
		len += ft_putchar((num % 16) + 48);
	}
	else
	{
		if (flag == 1)
			len += ft_putchar((num % 16) + 87);
		else
			len += ft_putchar((num % 16) + 55);
	}
	return (len);
}
