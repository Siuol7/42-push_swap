/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:55:04 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/21 19:40:14 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_sort	index;
	char	**array;
	int		*rank;
	int		*main;

	if (ac < 2)
	{
		ft_printf_fd(2, "Bad arguments");
		return (1);
	}
	array = parsing(++av);
	if (!*array)
		ft_printf_fd(2, "Error\n");
	return (0);
	
}
