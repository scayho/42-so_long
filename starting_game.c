/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:28:43 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 16:34:50 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_infos *j)
{
	int		width;
	int		hight;

	width = 0;
	hight = 0;
	j->mlx = mlx_init();
	j->x = ft_strlen(j->map[0]) * 73;
	j->y = ft_tablen(j->map) * 73;
	j->count = 0;
	j->mlx_win = mlx_new_window(j->mlx, j->x, j->y, "so_long");
	create_universe(j);
	mlx_hook(j->mlx_win, 2, 0, moves, j);
	mlx_loop(j->mlx);
}
	// mlx_hook(j->mlx_win, 17, 0, destruction, j);
