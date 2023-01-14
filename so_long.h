/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:00:46 by abelahce          #+#    #+#             */
/*   Updated: 2023/01/14 20:38:36 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_Data {
	char	**map;
	char	*hero;
	char	*col;
	char	*edge;
	char	*ground;
	char	*gate;
	char	*exited;
	int		player;
	int		colecteble;
	int		exit;
	int		i;
	int		b;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	void	*img;
	int		pl;
	int		pc;
	void	*player_adr;
	void	*ground_adr;
	int		count;
	int		ii;
	int		jj;
}		t_infos;

int		sstrlen(void);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strlen(char *str);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	parsing(char *str, t_infos *infos);
void	ft_putstr(char *str);
int		ft_tablen(char	**table);
void	check_pnj(char *map, t_infos *infos);
void	start_game(t_infos *infos);
void	create_universe(t_infos *j);
int		moves(int key, t_infos *j);
char	*read_map(char	*str);
void	move_right(t_infos *j, int key);
char	*read_map(char	*str);
void	ft_putnbr(int n);
void	move_left(t_infos *j, int key);
void	move_down(t_infos *j, int key);
void	move_player(t_infos *j, int check);
void	player_win(t_infos *j);
void	create_col(t_infos *j);
void	ft_putchar(char c);
char	*get_next_line(int fd);
void	check_path(t_infos *info);
void	checkmap(char	*str, t_infos *infos);
char	*ft_strjoin(char *s1, char *s2);
int		launch_search(int i, int j, char **map, int check);
int		launch_search2(int i, int j, char **map, int check);

#endif