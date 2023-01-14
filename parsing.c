/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:47:40 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 20:31:53 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	function_error(int i)
{
	if (i == 1)
		ft_putstr("file damaged\n");
	if (i == 2)
		ft_putstr("maps lanes are not aligned\n");
	if (i == 3)
		ft_putstr("maps edge damaged\n");
	exit (0);
}

void	check_lanes(char	*str, int j)
{
	int	i;

	i = 0;
	if (j == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'P' || str[i] == '1' || str[i] == '0'
				|| str[i] == 'E' || str[i] == 'C')
				i++;
			else
				function_error(3);
		}
		if (str[0] != '1' || str[i - 1] != '1')
			function_error(3);
	}
	else if (j == 2)
	{
		while (str[i] != '\0')
		{
			if (str[i] != '1')
				function_error(3);
			i++;
		}
	}
}

void	check_the_edge(char	**map)
{
	int	i;

	i = 0;
	while (i < ft_tablen(map) - 1)
	{
		check_lanes(map[i], 1);
		i++;
	}
	check_lanes(map[0], 2);
	check_lanes(map[i], 2);
}

void	checkmap(char	*str, t_infos *infos)
{
	int		i;
	char	*readed;
	char	**map;

	readed = read_map(str);
	check_pnj(readed, infos);
	i = 0;
	map = ft_split(readed, '\n');
	infos->map = map;
	while (map[i] != 0 && map[i + 1] != 0)
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			function_error(2);
	}
	check_the_edge(map);
	check_path(infos);
}

void	parsing(char *str, t_infos *infos)
{
	if ((ft_strncmp(str + ft_strlen(str) - 4, ".ber", 4)))
	{
		ft_putstr("unvalid map , map must be [.ber] type !\n");
		exit(0);
	}
	checkmap(str, infos);
}
