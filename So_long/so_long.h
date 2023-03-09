/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:43 by nchaknan          #+#    #+#             */
/*   Updated: 2023/03/07 20:25:02 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"

# define PLAYER_ERR "Your map must have one starting position, you have : "
# define COINS_ERR "Your map must have at least one collectible, you have : "
# define EXIT_ERR "Your map must have one exit, you have : "

# define WALL "./textures/wall.xpm"
# define BACKGROUND "./textures/background.xpm"
# define PLAYER "./textures/player.xpm"
# define COIN "./textures/collectible.xpm"
# define EXIT "./textures/exit.xpm"

typedef struct list
{
	char	*map_name;
	char	**array;
	char	**fakearray;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*bg;
	void	*player;
	void	*coin;
	void	*exit;
	int		width;
	int		height;
	int		pixels;
	int		player_count;
	int		coins_count;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		moves;
}	t_mylist;

void	identify_map(t_mylist *myList);
void	read_map(t_mylist *myList, char **array);
void	check_map(t_mylist *myList);
void	check_errors(t_mylist *myList);
void	draw_map(t_mylist *myList);
void	print_error(t_mylist *myList, char *str, int i);
void	print_error_str(t_mylist *myList, char *str);
int		count_lines(int fd);
int		map_strlen(char *s);
int		find_player_position(t_mylist *myList);
void	move_up(t_mylist *myList, char w);
void	move_down(t_mylist *myList, char s);
void	move_left(t_mylist *myList, char a);
void	move_right(t_mylist *myList, char d);
int		key_press(int keycode, t_mylist *myList);
int		ft_exit(t_mylist *myList);
void	ft_destroy(t_mylist *myList);
void	free_map(char **array);

#endif