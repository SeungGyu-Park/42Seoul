/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:18:37 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/27 02:48:37 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(int col, char queen[])
{
	int	i;

	i = -1;
	while (++i < col)
	{
		if (queen[i] == queen[col] || col - i == queen[col] - queen[i]
			|| col - i == queen[i] - queen[col])
			return (0);
	}
	return (1);
}

void	make_queen_pos(int col, char queen[], int *cnt)
{
	int	i;

	i = -1;
	if (col == 10)
	{
		while (++i < 10)
			ft_putchar(queen[i]);
		write(1, "\n", 1);
		(*cnt)++;
	}
	else
	{
		while (++i < 10)
		{
			queen[col] = i + '0';
			if (check(col, queen))
				make_queen_pos(col + 1, queen, cnt);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	 int	cnt;
	char	queen[10];

	cnt = 0;
	make_queen_pos(0, queen, &cnt);
	return (cnt);
}
