/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:16:30 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:20:00 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy(t_game *game, int x, int y)
{
	if (game->enemy.img_ptr == NULL)
	{
		game->enemy.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/enemy.xpm", \
				&(game->enemy.width), &(game->enemy.height));
		if (game->enemy.img_ptr == NULL)
		{
			free_game(game);
			exit_with_error("Failure in getting enemy image");
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->enemy.img_ptr, 64 * x, 64 * y);
}

void	put_enemys(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'X')
				put_enemy(game, x, y);
			x++;
		}
		y++;
	}
}
