/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:30:59 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:18:42 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define X_EVENT_PRESS_KEY 2
# define X_EVENT_RED_CROSS 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_loc
{
	int	dir;
	int	x;
	int	y;
}	t_loc;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		num_of_c;
	int		num_of_e;
	int		num_of_p;
	int		cnt;
	int		move;
	t_img	tile;
	t_img	wall;
	t_img	collect;
	t_img	character[4][4];
	t_img	exit;
	t_loc	loc;
}	t_game;

void	exit_with_error(char *message);

void	check_filename(int argc, char *argv[]);
int		get_file_size(char *filename);
char	*read_file(char *filename);

void	free_game(t_game *game);
void	check_map(t_game *game);

void	init_game(t_game *game);
void	put_tiles(t_game *game);
void	put_walls(t_game *game);
void	put_collectibles(t_game *game);
void	put_exits(t_game *game, int flag);

void	put_tile(t_game *game, int x, int y);
void	put_wall(t_game *game, int x, int y);
void	put_collectible(t_game *game, int x, int y);
void	put_exit(t_game *game, int x, int y, int flag);

void	set_character_up_img(t_game *game);
void	set_character_left_img(t_game *game);
void	set_character_down_img(t_game *game);
void	set_character_right_img(t_game *game);
void	put_character_img(t_game *game);

int		press_key(int key_in, t_game *game);
int		press_red_cross(t_game *game);

#endif
