/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_D_R.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:09:18 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 21:24:46 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_col(t_infos *j)
{
	int		x;
	int		y;
	void	*backgroud_parser;

	x = 0;
	y = 0;
	backgroud_parser = mlx_xpm_file_to_image(j->mlx \
	, "./textures/ground.xpm", &x, &y);
	if (!backgroud_parser)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, backgroud_parser, j->i, j->b);
	mlx_destroy_image(j->mlx, backgroud_parser);
	backgroud_parser = mlx_xpm_file_to_image(j->mlx \
	, "./textures/col.xpm", &x, &y);
	if (!backgroud_parser)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, backgroud_parser, j->i, j->b);
	mlx_destroy_image(j->mlx, backgroud_parser);
}

void	move_right(t_infos *j, int key)
{
	if ((j->map[j->pl][j->pc + 1] == '1') \
		|| (j->map[j->pl][j->pc + 1] == 'E' && j->colecteble > 0))
	{
		return ;
	}
	else if (j->map[j->pl][j->pc + 1] == 'C' || j->map[j->pl][j->pc + 1] == '0' \
	|| j->map[j->pl][j->pc + 1] == 'P')
	{
		if (j->map[j->pl][j->pc + 1] == 'C')
		{
			j->map[j->pl][j->pc + 1] = '0';
			j->colecteble--;
		}
		move_player(j, key);
	}
	else if (j->map[j->pl][j->pc + 1] == 'E' && j->colecteble == 0)
		player_win(j);
}

void	move_down(t_infos *j, int key)
{
	if ((j->map[j->pl + 1][j->pc] == '1') \
		|| (j->map[j->pl + 1][j->pc] == 'E' && j->colecteble > 0))
	{
		return ;
	}
	else if (j->map[j->pl + 1][j->pc] == 'C' || j->map[j->pl + 1][j->pc] == '0' \
	|| j->map[j->pl + 1][j->pc] == 'P')
	{
		if (j->map[j->pl + 1][j->pc] == 'C')
		{
			j->map[j->pl + 1][j->pc] = '0';
			j->colecteble--;
		}
		move_player(j, key);
	}
	else if (j->map[j->pl + 1][j->pc] == 'E' && j->colecteble == 0)
		player_win(j);
}

void	move_left(t_infos *j, int key)
{
	if ((j->map[j->pl][j->pc - 1] == '1') \
		|| (j->map[j->pl][j->pc - 1] == 'E' && j->colecteble > 0))
	{
		return ;
	}
	else if (j->map[j->pl][j->pc - 1] == 'C' || j->map[j->pl][j->pc - 1] == '0' \
	|| j->map[j->pl][j->pc - 1] == 'P')
	{
		if (j->map[j->pl][j->pc - 1] == 'C')
		{
			j->map[j->pl][j->pc - 1] = '0';
			j->colecteble--;
		}
		move_player(j, key);
	}
	else if (j->map[j->pl][j->pc - 1] == 'E' && j->colecteble == 0)
		player_win(j);
}
