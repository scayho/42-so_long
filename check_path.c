/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:39:33 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 21:00:06 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	launch_search2(int i, int j, char **map, int check)
{
	if (map[i][j - 1] != 'E' && map[i][j - 1] != '1' && !check)
	{
		if (map[i][j - 1] == 'P')
			check = 1;
		else
		{
			map[i][j] = '1';
			check = launch_search(i, j - 1, map, 0);
		}
	}
	if (map[i][j + 1] != 'E' && map[i][j + 1] != '1' && !check)
	{
		if (map[i][j + 1] == 'P')
			check = 1;
		else
		{
			map[i][j] = '1';
			check = launch_search(i, j + 1, map, 0);
		}
	}
	return (check);
}

int	launch_search(int i, int j, char **map, int check)
{
	if (map[i - 1][j] != 'E' && map[i - 1][j] != '1' && !check)
	{
		if (map[i - 1][j] == 'P')
			check = 1;
		else
		{
			map[i][j] = '1';
			check = launch_search(i - 1, j, map, 0);
		}
	}
	if (map[i + 1][j] != 'E' && map[i + 1][j] != '1' && !check)
	{
		if (map[i + 1][j] == 'P')
			check = 1;
		else
		{
			map[i][j] = '1';
			check = launch_search(i + 1, j, map, 0);
		}
	}
	check = launch_search2(i, j, map, check);
	return (check);
}

char	**cpy_map(char **s)
{
	char	**d;
	int		i;

	i = 0;
	d = malloc((ft_tablen(s) + 1) * sizeof(char *));
	if (!d)
	{
		ft_putstr("malloc map path");
		exit(0);
	}
	while (s[i])
	{
		d[i] = ft_strdup(s[i]);
		i++;
	}
	d[i] = NULL;
	return (d);
}

void	look_for_path(int i, int j, char **map)
{
	map = cpy_map(map);
	if (launch_search(i, j, map, 0) == 0)
	{
		ft_putstr("there isn o valid path for the player to win the game\n");
		exit(0);
	}
	free_table(map);
}

void	check_path(t_infos *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'C' || info->map[i][j] == 'E')
				look_for_path(i, j, info->map);
			j++;
		}
		j = 0;
		i++;
	}
}
