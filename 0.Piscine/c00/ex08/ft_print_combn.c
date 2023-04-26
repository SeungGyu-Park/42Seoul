/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:43:07 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/21 20:12:57 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int *arr, int n)
{
	char	c;
	 int	i;

	i = -1;
	while (++i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		if (i == n - 1)
		{
			if (arr[0] == 9 - (n - 1))
			{
				return ;
			}	
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	make_comb(int dep, int i, int *arr, int n)
{
	if (dep >= n)
	{
		print_comb(arr, n);
		return ;
	}
	while (i <= 9)
	{
		arr[dep] = i;
		i++;
		make_comb(dep + 1, i, arr, n);
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	make_comb(0, 0, arr, n);
}
