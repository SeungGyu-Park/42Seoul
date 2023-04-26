/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:40:23 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:19:27 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_tiles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	put_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				put_wall(game, x, y);
			x++;
		}
		y++;
	}
}

void	put_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				put_collectible(game, x, y);
			x++;
		}
		y++;
	}
}

void	put_exits(t_game *game, int flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				put_exit(game, x, y, flag);
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
							64 * (game->width), 64 * (game->height), "so_long");
	if (game->win_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in mlx_new_window()");
	}
	put_tiles(game);
	put_walls(game);
	put_collectibles(game);
	put_exits(game, 0);
	put_character_img(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->character[2][0].img_ptr, 64 * game->loc.x, 64 * game->loc.y);
	put_enemys(game);
	game->map[game->loc.y][game->loc.x] = '0';
	mlx_hook(game->win_ptr, X_EVENT_PRESS_KEY, 0, press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_RED_CROSS, 0, press_red_cross, game);
	mlx_loop(game->mlx_ptr);
}
