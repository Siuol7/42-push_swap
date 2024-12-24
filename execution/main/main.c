/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:55:04 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/23 10:43:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf_fd(2, "Bad arguments");
		return (1);
	}
	if (!utilities(ac, av))
	{
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	return (0);
}
