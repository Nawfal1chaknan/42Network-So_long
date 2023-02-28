/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:23:07 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/28 02:11:25 by nchaknan         ###   ########.fr       */
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
}

void	identify_map(t_mylist *myList)
{
	check_map_format(myList->map_name);
	myList->array = malloc(sizeof(char *) * 1024);
	read_map(myList, myList->array);
	myList->width = map_strlen(myList->array[0]);
	myList->pixels = 48;
	myList->mlx = mlx_init();
	myList->window = mlx_new_window(myList->mlx, myList->pixels
			* myList->width, myList->pixels * myList->height, "So Long");
	myList->wall = mlx_xpm_file_to_image(myList->mlx, WALL,
			&myList->pixels, &myList->pixels);
	myList->bg = mlx_xpm_file_to_image(myList->mlx, BACKGROUND,
			&myList->pixels, &myList->pixels);
	myList->player = mlx_xpm_file_to_image(myList->mlx, PLAYER,
			&myList->pixels, &myList->pixels);
	myList->coin = mlx_xpm_file_to_image(myList->mlx, COIN,
			&myList->pixels, &myList->pixels);
	myList->exit = mlx_xpm_file_to_image(myList->mlx, EXIT,
			&myList->pixels, &myList->pixels);
	myList->player_count = 0;
	myList->coins_count = 0;
	myList->exit_count = 0;
	myList->moves = 0;
	find_player_position(myList);
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
