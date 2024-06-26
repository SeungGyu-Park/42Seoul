/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_character_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:06:02 by seunggpa          #+#    #+#             */
/*   Updated: 2022/08/11 02:19:46 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_character_up_img(t_game *game)
{
	game->character[0][0].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/up0.xpm", \
			&(game->character[0][0].width), &(game->character[0][0].height));
	game->character[0][1].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/up1.xpm", \
			&(game->character[0][1].width), &(game->character[0][1].height));
	game->character[0][2].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/up2.xpm", \
			&(game->character[0][2].width), &(game->character[0][2].height));
	game->character[0][3].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/up3.xpm", \
			&(game->character[0][3].width), &(game->character[0][3].height));
	if (!(game->character[0][0].img_ptr) || !(game->character[0][1].img_ptr) || \
		!(game->character[0][2].img_ptr) || !(game->character[0][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's up image");
	}
}

void	set_character_left_img(t_game *game)
{
	game->character[1][0].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/left0.xpm", \
			&(game->character[1][0].width), &(game->character[1][0].height));
	game->character[1][1].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/left1.xpm", \
			&(game->character[1][1].width), &(game->character[1][1].height));
	game->character[1][2].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/left2.xpm", \
			&(game->character[1][2].width), &(game->character[1][2].height));
	game->character[1][3].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/left3.xpm", \
			&(game->character[1][3].width), &(game->character[1][3].height));
	if (!(game->character[1][0].img_ptr) || !(game->character[1][1].img_ptr) || \
		!(game->character[1][2].img_ptr) || !(game->character[1][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's left image");
	}
}

void	set_character_down_img(t_game *game)
{
	game->character[2][0].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/down0.xpm", \
			&(game->character[2][0].width), &(game->character[2][0].height));
	game->character[2][1].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/down1.xpm", \
			&(game->character[2][1].width), &(game->character[2][1].height));
	game->character[2][2].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/down2.xpm", \
			&(game->character[2][2].width), &(game->character[2][2].height));
	game->character[2][3].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/down3.xpm", \
			&(game->character[2][3].width), &(game->character[2][3].height));
	if (!(game->character[2][0].img_ptr) || !(game->character[2][1].img_ptr) || \
		!(game->character[2][2].img_ptr) || !(game->character[2][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's down image");
	}
}

void	set_character_right_img(t_game *game)
{
	game->character[3][0].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/right0.xpm", \
			&(game->character[3][0].width), &(game->character[3][0].height));
	game->character[3][1].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/right1.xpm", \
			&(game->character[3][1].width), &(game->character[3][1].height));
	game->character[3][2].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/right2.xpm", \
			&(game->character[3][2].width), &(game->character[3][2].height));
	game->character[3][3].img_ptr = mlx_xpm_file_to_image(\
			game->mlx_ptr, "imgs/character/right3.xpm", \
			&(game->character[3][3].width), &(game->character[3][3].height));
	if (!(game->character[3][0].img_ptr) || !(game->character[3][1].img_ptr) || \
		!(game->character[3][2].img_ptr) || !(game->character[3][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's right image");
	}
}

void	put_character_img(t_game *game)
{
	set_character_up_img(game);
	set_character_left_img(game);
	set_character_down_img(game);
	set_character_right_img(game);
}
