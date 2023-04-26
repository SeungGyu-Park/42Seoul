/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:42:02 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/21 20:12:49 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_num(int x, int y)
{
	ft_putchar('0' + x / 10);
	ft_putchar('0' + x % 10);
	ft_putchar(' ');
	ft_putchar('0' + y / 10);
	ft_putchar('0' + y % 10);
	if (!(x == 98 && y == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_print_num(x, y);
			y++;
		}
		x++;
	}
}
