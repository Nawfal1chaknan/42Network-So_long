/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:42:26 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/25 22:42:55 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_mylist *myList, char *str, int i)
{
	printf("%s%d !\n", str, i);
	ft_destroy(myList);
	exit(1);
}

void	print_error_str(t_mylist *myList, char *str)
{
	printf("%s !\n", str);
	ft_destroy(myList);
	exit(1);
}

int	ft_exit(t_mylist *myList)
{
	ft_destroy(myList);
	exit(0);
}
