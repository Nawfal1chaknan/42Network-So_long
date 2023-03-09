/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:23:07 by nchaknan          #+#    #+#             */
/*   Updated: 2023/03/07 19:52:28 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_format(char *av)
{
	int		i;
	char	point;
	char	b;
	char	e;
	char	r;

	i = map_strlen(av) - 1;
	point = av[i - 3];
	b = av[i - 2];
	e = av[i - 1];
	r = av[i];
	if (point != '.' || b != 'b' || e != 'e' || r != 'r')
	{
		ft_printf("Your map file should be in .ber format !\n");
		exit(1);
	}	
}

void	read_map(t_mylist *myList, char **array)
{
	int	fd;
	int	i;

	fd = open(myList->map_name, O_RDONLY);
	myList->height = count_lines(fd);
	fd = open(myList->map_name, O_RDONLY);
	i = 0;
	while (i < myList->height)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	myList->player_count = 0;
	myList->coins_count = 0;
	myList->exit_count = 0;
	myList->moves = 0;
	find_player_position(myList);
}

void	identify_map(t_mylist *list)
{
	check_map_format(list->map_name);
	list->array = malloc(sizeof(char *) * 1024);
	read_map(list, list->array);
	list->width = map_strlen(list->array[0]);
	list->pixels = 48;
	list->mlx = mlx_init();
	list->window = mlx_new_window(list->mlx, list->pixels
			* list->width, list->pixels * list->height, "So Long");
	list->wall = mlx_xpm_file_to_image(list->mlx, WALL,
			&list->pixels, &list->pixels);
	list->bg = mlx_xpm_file_to_image(list->mlx, BACKGROUND,
			&list->pixels, &list->pixels);
	list->player = mlx_xpm_file_to_image(list->mlx, PLAYER,
			&list->pixels, &list->pixels);
	list->coin = mlx_xpm_file_to_image(list->mlx, COIN,
			&list->pixels, &list->pixels);
	list->exit = mlx_xpm_file_to_image(list->mlx, EXIT,
			&list->pixels, &list->pixels);
	if (!list->wall || !list->bg || !list->player
		|| !list->coin || !list->exit)
		print_error_str(list, "Somthing is wrong with your xpm images");
}

void	put_images(t_mylist *list, int x, int y)
{
	mlx_put_image_to_window(list->mlx, list->window, list->bg,
		x * list->pixels, y * list->pixels);
	if (list->array[y][x] == '1')
		mlx_put_image_to_window(list->mlx, list->window, list->wall,
			x * list->pixels, y * list->pixels);
	else if (list->array[y][x] == 'P')
		mlx_put_image_to_window(list->mlx, list->window, list->player,
			x * list->pixels, y * list->pixels);
	else if (list->array[y][x] == 'C')
		mlx_put_image_to_window(list->mlx, list->window, list->coin,
			x * list->pixels, y * list->pixels);
	else if (list->array[y][x] == 'E')
		mlx_put_image_to_window(list->mlx, list->window, list->exit,
			x * list->pixels, y * list->pixels);
	else
		mlx_put_image_to_window(list->mlx, list->window, list->bg,
			x * list->pixels, y * list->pixels);
}

void	draw_map(t_mylist *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->height)
	{
		x = 0;
		while (x < list->width)
		{
			put_images(list, x, y);
			x++;
		}
		y++;
	}
}
