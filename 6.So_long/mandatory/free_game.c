/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:50:57 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:17:05 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_game *game)
{
	int	i;
	int	j;

	if (game->tile.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->tile.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	if (game->collect.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collect.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (game->character[i][j].img_ptr)
				mlx_destroy_image(game->mlx_ptr, game->character[i][j].img_ptr);
		}
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	free_imgs(game);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}
