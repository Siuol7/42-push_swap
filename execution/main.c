/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:55:04 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/19 10:56:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf_fd(2, "Bad arguments");
		return (1);
	}
	//->Parse &av
	if (!parsing(av))
		return (1);
	return (0);
}