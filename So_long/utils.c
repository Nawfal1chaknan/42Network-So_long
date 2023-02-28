/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:11:41 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/28 02:11:44 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	int		i;
	char	*lines;

	i = 0;
	while (1)
	{
		lines = get_next_line(fd);
		if (lines == NULL)
		{
			close(fd);
			return (i);
		}
		i++;
		free(lines);
	}
	return (i);
}

int	map_strlen(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
			j--;
		i++;
		j++;
	}
	return (j);
}

void	free_map(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	ft_destroy(t_mylist *myList)
{
	if (myList->wall)
		mlx_destroy_image(myList->mlx, myList->wall);
	if (myList->coin)
		mlx_destroy_image(myList->mlx, myList->coin);
	if (myList->bg)
		mlx_destroy_image(myList->mlx, myList->bg);
	if (myList->exit)
		mlx_destroy_image(myList->mlx, myList->exit);
	if (myList->window)
		mlx_destroy_window(myList->mlx, myList->window);
	free_map(myList->array);
}
