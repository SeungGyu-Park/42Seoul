/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:15:51 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/25 16:08:04 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	         char	*hex;
	unsigned char	tmp;

	hex = "0123456789abcdef";
	while (*str)
	{
		tmp = (unsigned char)*str;
		if (!(32 <= tmp && tmp <= 126))
		{
			write(1, "\\", 1);
			ft_putchar(hex[tmp / 16]);
			ft_putchar(hex[tmp % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
