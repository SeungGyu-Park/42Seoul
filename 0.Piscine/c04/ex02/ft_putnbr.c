/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:57:35 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/23 16:17:50 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char ch)
{
	write(1, &ch, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		put_char('-');
		i = -nb;
	}
	if (i < 10)
	{
		put_char(i + '0');
		return ;
	}
	ft_putnbr(i / 10);
	put_char((i % 10) + '0');
}
