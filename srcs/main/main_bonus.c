/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:58:26 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 08:49:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	else if (!checker(av))
	{
		ft_printf_fd(2, "KO\n");
		return (1);
	}
	ft_printf_fd(1, "OK\n");
	return (0);
}
