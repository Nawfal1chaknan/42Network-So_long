/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:18:27 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/25 22:36:24 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mylist *myList, char w)
{
	if (w != 'E')
	{
		if (w == 'C')
			myList->coins_count--;
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[--myList->player_y][myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
	}
	else if (myList->coins_count == 0)
	{
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[--myList->player_y][myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
		ft_exit(myList);
	}
}

void	move_down(t_mylist *myList, char s)
{
	if (s != 'E')
	{
		if (s == 'C')
			myList->coins_count--;
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[++myList->player_y][myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
	}
	else if (myList->coins_count == 0)
	{
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[++myList->player_y][myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
		ft_exit(myList);
	}
}

void	move_left(t_mylist *myList, char a)
{
	if (a != 'E')
	{
		if (a == 'C')
			myList->coins_count--;
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[myList->player_y][--myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
	}
	else if (myList->coins_count == 0)
	{
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[myList->player_y][--myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
		ft_exit(myList);
	}
}

void	move_right(t_mylist *myList, char d)
{
	if (d != 'E')
	{
		if (d == 'C')
			myList->coins_count--;
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[myList->player_y][++myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
	}
	else if (myList->coins_count == 0)
	{
		myList->array[myList->player_y][myList->player_x] = '0';
		myList->array[myList->player_y][++myList->player_x] = 'P';
		printf("moves : %d\n", ++myList->moves);
		ft_exit(myList);
	}
}
