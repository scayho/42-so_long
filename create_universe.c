/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_universe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:14:05 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 21:24:40 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_edge(t_infos *j)
{
	int		x;
	int		y;
	void	*backgroud_parser;

	x = 0;
	y = 0;
	backgroud_parser = mlx_xpm_file_to_image(j->mlx \
	, "./textures/edge.xpm", &x, &y);
	if (!backgroud_parser)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, backgroud_parser, j->i, j->b);
	mlx_destroy_image(j->mlx, backgroud_parser);
}

void	create_ground(t_infos *j)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	j->ground_adr = mlx_xpm_file_to_image(j->mlx \
	, "./textures/ground.xpm", &x, &y);
	if (!j->ground)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, j->ground_adr, j->i, j->b);
}

void	create_player(t_infos *j)
{
	int		width;
	int		hight;
	void	*backgroud_parser;

	width = 0;
	hight = 0;
	j->pl = j->x;
	j->pc = j->y;
	j->ground_adr = mlx_xpm_file_to_image(j->mlx \
	, "./textures/ground.xpm", &width, &hight);
	if (!j->ground_adr)
		exit(0);
	mlx_put_image_to_window(j->mlx \
	, j->mlx_win, j->ground_adr, j->i, j->b);
	backgroud_parser = mlx_xpm_file_to_image(j->mlx \
	, "./textures/playerx.xpm", &width, &hight);
	if (!backgroud_parser)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win \
	, backgroud_parser, j->y * 73, j->x * 73);
	mlx_destroy_image(j->mlx, backgroud_parser);
}

void	create_exit(t_infos *j)
{
	int		x;
	int		y;
	void	*backgroud_parser;

	x = 0;
	y = 0;
	backgroud_parser = mlx_xpm_file_to_image(j->mlx \
	, "./textures/gate.xpm", &x, &y);
	if (!backgroud_parser)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, backgroud_parser, j->i, j->b);
	mlx_destroy_image(j->mlx, backgroud_parser);
}

void	create_universe(t_infos *j)
{
	j->x = -1;
	while (j->map[++j->x])
	{
		j->y = 0;
		j->i = 0;
		while (j->map[j->x][j->y])
		{
			if (j->map[j->x][j->y] == '1')
				create_edge(j);
			else if (j->map[j->x][j->y] == '0')
				create_ground(j);
			else if (j->map[j->x][j->y] == 'P')
				create_player(j);
			else if (j->map[j->x][j->y] == 'E')
				create_exit(j);
			else if (j->map[j->x][j->y] == 'C')
				create_col(j);
			j->i += 73;
			j->y++;
		}
		j->b += 73;
	}
}
