/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:41:26 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:18:33 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(char *message)
{
	printf("Error\n");
	perror(message);
	exit(EXIT_FAILURE);
}

static void	init(t_game *game)
{
	int	i;
	int	j;

	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->height = 0;
	game->width = 0;
	game->map = 0;
	game->cnt = 0;
	game->num_of_c = 0;
	game->num_of_e = 0;
	game->num_of_p = 0;
	game->loc.dir = 0;
	game->move = 0;
	game->tile.img_ptr = NULL;
	game->wall.img_ptr = NULL;
	game->collect.img_ptr = NULL;
	game->exit.img_ptr = NULL;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			game->character[i][j].img_ptr = NULL;
	}
}

int	main(int argc, char *argv[])
{
	char	*buffer;
	t_game	game;

	check_filename(argc, argv);
	init(&game);
	buffer = read_file(argv[1]);
	game.map = ft_split(buffer, '\n');
	free(buffer);
	if (game.map == 0)
		exit_with_error("Failure in splitting buffer to map");
	check_map(&game);
	init_game(&game);
}
