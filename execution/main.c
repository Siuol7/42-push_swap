/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:55:04 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 05:30:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**array;

	if (ac < 2)
	{
		ft_printf_fd(2, "Bad arguments");
		return (1);
	}
	array = parsing(++av);
	if (!*array)
		ft_printf_fd(2, "Error\n");
	int i = 0;
	while (av[i])
		ft_printf_fd(1, "%s\n", av[i]);
	return (0);
}
