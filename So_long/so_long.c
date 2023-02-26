/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:32:19 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/25 22:36:24 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mylist	list;

	identify_map(&list);
	check_map(&list);
	draw_map(&list);
	mlx_hook(list.window, 2, 0, key_press, &list);
	mlx_hook(list.window, 17, 0, ft_exit, &list);
	mlx_loop(list.mlx);
}
