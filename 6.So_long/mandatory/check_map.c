/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:08:48 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:15:25 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_game_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	game->width = ft_strlen(game->map[0]);
	if (game->height < 3 || game->width < 3)
	{
		free_game(game);
		exit_with_error("Failure by map size");
	}
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
		{
			free_game(game);
			exit_with_error("Failure by width of map");
		}
		i++;
	}
}

static int	check_outline(t_game *game)
{
	int	i;
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	i = 0;
	while (i < h)
	{
		if (game->map[i][0] != '1' || game->map[i][w - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < w)
	{
		if (game->map[0][i] != '1' || game->map[h - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	count_contents(char content, int x, int y, t_game *game)
{
	if (content == 'P')
	{
		(game->num_of_p)++;
		game->loc.x = x;
		game->loc.y = y;
	}
	else if (content == 'E')
		(game->num_of_e)++;
	else if (content == 'C')
		(game->num_of_c)++;
}

static int	check_contents(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P' || game->map[y][x] == 'C' \
					|| game->map[y][x] == 'E')
				count_contents(game->map[y][x], x, y, game);
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	get_game_size(game);
	if (check_outline(game) || check_contents(game))
	{
		free_game(game);
		exit_with_error("Failure by format of map");
	}
	if (game->num_of_c == 0)
	{
		free_game(game);
		exit_with_error("Failure by number of collection");
	}
	if (game->num_of_e == 0)
	{
		free_game(game);
		exit_with_error("Failure by number of exit");
	}
	if (game->num_of_p != 1)
	{
		free_game(game);
		exit_with_error("Failure by number of starting position");
	}
}
