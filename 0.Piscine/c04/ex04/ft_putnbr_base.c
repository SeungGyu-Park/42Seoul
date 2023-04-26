/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:14:16 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/25 20:55:55 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(long long nbr, char *base, long long ibase)
{
	if (!nbr)
		return ;
	print(nbr / ibase, base, ibase);
	write(1, &base[nbr % ibase], 1);
}

long long	find_ibase(char *base)
{
	long long	i;
	     char	ch[256];

	i = -1;
	while (++i < 256)
		ch[i] = 0;
	i = -1;
	while (base[++i])
	{
		if (ch[(int)base[i]] || base[i] == '+' || base[i] == '-')
			return (0);
		ch[(int)base[i]] = 1;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	tmp;
	long long	ibase;

	ibase = find_ibase(base);
	if (ibase <= 1)
		return ;
	tmp = nbr;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = tmp * -1;
	}
	print(tmp, base, ibase);
}
