/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pnj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:09:21 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 16:41:31 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_pnj(t_infos *infos)
{
	if (infos->colecteble < 1)
	{
		ft_putstr("you don't have enough colectebles \n");
		exit(0);
	}
	if (infos->player != 1)
	{
		ft_putstr("you don't have a player or you have mores x0\n");
		exit(0);
	}
	if (infos->exit != 1)
	{
		ft_putstr("you nothing to run through \n");
		exit(0);
	}
}

void	check_pnj(char *map, t_infos *infos)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_putstr("you have got an empty lane\n");
			exit (0);
		}
		if (map[i] == 'P')
			infos->player++;
		else if (map[i] == 'E')
			infos->exit++;
		else if (map[i] == 'C')
			infos->colecteble++;
		i++;
	}
	if (map[i - 1] == '\n' || map[0] == '\n')
	{
		ft_putstr("you have got an error in your map\n");
		exit (0);
	}
	validate_pnj(infos);
}
