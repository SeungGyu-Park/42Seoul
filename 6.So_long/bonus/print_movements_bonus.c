/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:55:05 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:19:36 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	refresh_first_line(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		put_tile(game, x, 0);
		put_wall(game, x, 0);
		x++;
	}
}

void	print_movements(t_game *game)
{
	char	*num;
	char	*message;

	num = ft_itoa(game->move);
	if (!num)
	{
		free_game(game);
		exit_with_error("Failure in allocating number");
	}
	message = ft_strjoin("current number of move : ", num);
	free(num);
	if (!message)
	{
		free_game(game);
		exit_with_error("Failure in joining number with message");
	}
	refresh_first_line(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 32, 0xFF0000, message);
	free(message);
}
