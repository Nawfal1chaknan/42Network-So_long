/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:34:40 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/25 22:36:24 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_path(t_mylist *myList, char	**f_array)
{
	int		x;
	int		y;

	y = 0;
	while (y < myList->height)
	{
		x = 0;
		while (x < myList->width)
		{
			if (f_array[y][x] == 'P')
			{
				if (f_array[y - 1][x] != '1' && f_array[y - 1][x] != 'E')
					f_array[y - 1][x] = 'P';
				if (f_array[y + 1][x] != '1' && f_array[y + 1][x] != 'E')
					f_array[y + 1][x] = 'P';
				if (f_array[y][x - 1] != '1' && f_array[y][x - 1] != 'E')
					f_array[y][x - 1] = 'P';
				if (f_array[y][x + 1] != '1' && f_array[y][x + 1] != 'E')
					f_array[y][x + 1] = 'P';
			}
			x++;
		}
		y++;
	}
}

void	check_if_valid(t_mylist *myList, char **f_array)
{
	int	x;
	int	y;

	y = 0;
	while (y < myList->height)
	{
		x = 0;
		while (x < myList->width)
		{
			if (f_array[y][x] == 'C')
				print_error_str(myList, "Your map needs a valid path");
			if (f_array[y][x] == 'E')
			{
				if (f_array[y - 1][x] != 'P' && f_array[y + 1][x] != 'P'
					&& f_array[y][x - 1] != 'P' && f_array[y][x + 1] != 'P')
					print_error_str(myList, "Your have invalid path");
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_mylist *myList)
{
	int	i;

	myList->fakearray = malloc(sizeof(char *) * 1024);
	read_map(myList, myList->fakearray);
	check_errors(myList);
	i = 0;
	while (i++ != (myList->width + myList->height) * 2)
		draw_path(myList, myList->fakearray);
	check_if_valid(myList, myList->fakearray);
}
