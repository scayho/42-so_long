/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:00:44 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 21:01:10 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char	*str)
{
	int		check;
	int		fd;
	char	*buf;
	char	*map;

	map = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("unable to open the map!!\n");
		exit(0);
	}
	buf = malloc(2);
	check = read(fd, buf, 1);
	buf[1] = '\0';
	while (check > 0)
	{
		map = ft_strjoin(map, buf);
		check = read(fd, buf, 1);
		buf[1] = '\0';
	}
	free(buf);
	return (map);
}

int	main(int arc, char **arv)
{
	t_infos	*infos;

	infos = malloc(sizeof(t_infos));
	infos->player = 0;
	infos->colecteble = 0;
	infos->exit = 0;
	infos->i = 0;
	infos->b = 0;
	infos->count = 0;
	if (arc == 2)
		parsing(arv[1], infos);
	else
	{
		ft_putstr("not enough parameters !\n");
		exit (0);
	}
	// system("leaks so_long");
	start_game(infos);
}
