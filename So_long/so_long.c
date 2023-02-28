/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:32:19 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/28 02:11:32 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mylist	list;

	if (ac == 2)
	{
		list.map_name = av[1];
		identify_map(&list);
		check_map(&list);
		draw_map(&list);
		mlx_hook(list.window, 2, 0, key_press, &list);
		mlx_hook(list.window, 17, 0, ft_exit, &list);
		mlx_loop(list.mlx);
	}
}
