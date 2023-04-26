/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:10:57 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:19:13 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	refresh_cur_pos(t_game *game, int cur_x, int cur_y)
{
	put_tile(game, cur_x, cur_y);
	if (game->map[cur_y][cur_x] == 'E')
	{
		if (game->cnt == game->num_of_c)
			put_exit(game, cur_x, cur_y, 1);
		else
			put_exit(game, cur_x, cur_y, 0);
	}
}

void	move_to_new_pos(t_game *game, int new_dir, int new_x, int new_y)
{
	game->loc.dir = new_dir;
	if (game->map[new_y][new_x] != '1')
	{
		game->loc.x = new_x;
		game->loc.y = new_y;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->character[game->loc.dir][game->move % 4].img_ptr, \
					64 * game->loc.x, 64 * game->loc.y);
}

void	check_new_pos(t_game *game)
{
	if (game->map[game->loc.y][game->loc.x] == 'E')
	{
		if (game->cnt == game->num_of_c)
		{
			printf("SUCCESS !\n");
			press_red_cross(game);
		}
	}
	else if (game->map[game->loc.y][game->loc.x] == 'C')
	{
		(game->cnt)++;
		game->map[game->loc.y][game->loc.x] = '0';
		put_tile(game, game->loc.x, game->loc.y);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
						game->character[game->loc.dir][game->move % 4].img_ptr, \
						64 * game->loc.x, 64 * game->loc.y);
		if (game->cnt == game->num_of_c)
			put_exits(game, 1);
	}
	else if (game->map[game->loc.y][game->loc.x] == 'X')
	{
		printf("FAILURE !\n");
		press_red_cross(game);
	}
}

int	press_key(int key_in, t_game *game)
{
	if (key_in == KEY_ESC)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	if (key_in == KEY_W || key_in == KEY_A || \
		key_in == KEY_S || key_in == KEY_D)
	{
		(game->move)++;
		refresh_cur_pos(game, game->loc.x, game->loc.y);
		if (key_in == KEY_W)
			move_to_new_pos(game, 0, game->loc.x, game->loc.y - 1);
		else if (key_in == KEY_A)
			move_to_new_pos(game, 1, game->loc.x - 1, game->loc.y);
		else if (key_in == KEY_S)
			move_to_new_pos(game, 2, game->loc.x, game->loc.y + 1);
		else if (key_in == KEY_D)
			move_to_new_pos(game, 3, game->loc.x + 1, game->loc.y);
		check_new_pos(game);
		print_movements(game);
	}
	return (0);
}

int	press_red_cross(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
