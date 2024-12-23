/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:55:04 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 19:22:09 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*rank;
	// int		*main_arr;

	if (ac < 2)
	{
		ft_printf_fd(2, "Bad arguments");
		return (1);
	}
	rank = parsing(++av);
	mergesort(&rank,0, 7);
	if (!*rank)
	{
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	int i = 0;
	while (rank[i])
		ft_printf_fd(1, "%d\n", rank[i++]);
	return (0);
}
