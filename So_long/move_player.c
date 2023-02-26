/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:06:05 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/25 22:36:24 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_position(t_mylist *myList)
{
	int	x;
	int	y;

	y = 0;
	while (y < myList->height)
	{
		x = 0;
		while (x < myList->width)
		{
			if (myList->array[y][x] == 'P')
			{
				myList->player_x = x;
				myList->player_y = y;
				return (0);
			}
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	key_press(int keycode, t_mylist *myList)
{
	char	w;
	char	s;
	char	a;
	char	d;

	w = myList->array[myList->player_y - 1][myList->player_x];
	s = myList->array[myList->player_y + 1][myList->player_x];
	a = myList->array[myList->player_y][myList->player_x - 1];
	d = myList->array[myList->player_y][myList->player_x + 1];
	if (keycode == 13 && w != '1')
		move_up(myList, w);
	else if (keycode == 1 && s != '1')
		move_down(myList, s);
	else if (keycode == 0 && a != '1')
		move_left(myList, a);
	else if (keycode == 2 && d != '1')
		move_right(myList, d);
	else if (keycode == 53)
		ft_exit(myList);
	draw_map(myList);
	return (0);
}
