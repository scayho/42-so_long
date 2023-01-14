/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:36:47 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 21:25:10 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_infos *j, int check)
{
	void	*newadr;

	j->count++;
	ft_putnbr(j->count);
	ft_putchar('\n');
	j->ii = 0;
	j->jj = 0;
	newadr = mlx_xpm_file_to_image(j->mlx \
	, "./textures/ground.xpm", &j->ii, &j->jj);
	if (!newadr)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, newadr, j->pc * 73, j->pl * 73);
	mlx_destroy_image(j->mlx, newadr);
	if (check == 13)
		j->pl--;
	if (check == 2)
		j->pc++;
	if (check == 1)
		j->pl++;
	if (check == 0)
		j->pc--;
	mlx_put_image_to_window(j->mlx, j->mlx_win \
	, j->ground_adr, j->pc * 73, j->pl * 73);
	newadr = mlx_xpm_file_to_image(j->mlx \
	, "./textures/playerx.xpm", &j->ii, &j->jj);
	if (!newadr)
		exit(0);
	mlx_put_image_to_window(j->mlx, j->mlx_win, newadr, j->pc * 73, j->pl * 73);
	mlx_destroy_image(j->mlx, newadr);
}

void	player_win(t_infos *j)
{
	j->count++;
	ft_putnbr(j->count++);
	ft_putchar('\n');
	ft_putstr("your player has WON with {");
	ft_putnbr(j->count);
	ft_putstr("} moves");
	ft_putchar('\n');
	exit (0);
}

int	move_up(t_infos *j, int key)
{
	if ((j->map[j->pl - 1][j->pc] == '1') \
	|| (j->map[j->pl - 1][j->pc] == 'E' && j->colecteble > 0))
	{
		return (0);
	}
	else if (j->map[j->pl - 1][j->pc] == 'C' || j->map[j->pl - 1][j->pc] == '0' \
	|| j->map[j->pl - 1][j->pc] == 'P')
	{
		if (j->map[j->pl - 1][j->pc] == 'C')
		{
			j->map[j->pl - 1][j->pc] = '0';
			j->colecteble--;
		}
		move_player(j, key);
	}
	else if (j->map[j->pl - 1][j->pc] == 'E' && j->colecteble == 0)
		player_win(j);
	return (0);
}

int	moves(int key, t_infos *j)
{
	if (key == 53)
	{
		mlx_destroy_window(j->mlx, j->mlx_win);
		ft_putstr("quite successfully !\n");
		exit(0);
	}
	if (key == 13)
		move_up(j, key);
	if (key == 2)
		move_right(j, key);
	if (key == 1)
		move_down(j, key);
	if (key == 0)
		move_left(j, key);
	return (0);
}
