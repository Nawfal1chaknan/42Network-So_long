/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:58:41 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/28 02:49:04 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Error : Map composed of only with 0,1,C,E,P.
void	error_one(t_mylist *myList)
{
	int		x;
	int		y;
	char	p;

	y = 0;
	while (y < myList->height)
	{
		x = 0;
		while (x < myList->width)
		{
			p = myList->array[y][x];
			if (p != '0' && p != '1' && p != 'C' && p != 'E' && p != 'P')
				print_error_str(myList,
					"Your map can be composed of only with 0,1,C,E,P");
			x++;
		}
		y++;
	}
}

// Error : 1 Player 1 Exit 1 or more Coin.
void	error_two(t_mylist *myList)
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
				myList->player_count++;
			else if (myList->array[y][x] == 'C')
				myList->coins_count++;
			else if (myList->array[y][x] == 'E')
				myList->exit_count++;
			x++;
		}
		y++;
	}
	if (myList->player_count != 1)
		print_error(myList, PLAYER_ERR, myList->player_count);
	if (myList->coins_count < 1)
		print_error(myList, COINS_ERR, myList->coins_count);
	if (myList->exit_count != 1)
		print_error(myList, EXIT_ERR, myList->exit_count);
}

// Error : Rectangular map
void	error_three(t_mylist *myList)
{
	int	j;

	j = 0;
	while (j < myList->height)
	{
		if (map_strlen(myList->array[0]) != map_strlen(myList->array[j]))
			print_error_str(myList, "Your map must be rectangular");
		else
			j++;
	}
}

// Error : Map surrounded by walls
void	error_four(t_mylist *myList)
{
	int	l;
	int	m;
	int	last_l;
	int	right_w;

	last_l = myList->height - 1;
	l = 0;
	while (l < myList->width)
	{
		if ((myList->array[0][l] != '1') || (myList->array[last_l][l] != '1'))
			print_error_str(myList, "Your map is not surrounded by walls");
		l++;
	}
	right_w = myList->width - 1;
	m = 0;
	while (m < myList->height)
	{
		if (myList->array[m][0] != '1' || myList->array[m][right_w] != '1')
			print_error_str(myList, "Your map is not surrounded by walls");
		m++;
	}
}

void	check_errors(t_mylist *myList)
{
	error_one(myList);
	error_two(myList);
	error_three(myList);
	error_four(myList);
}
