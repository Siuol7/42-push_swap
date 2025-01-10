/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:58:26 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 08:37:56 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int	status;

	status = 0;
	if (ac < 2)
		return (0);
	checker(av, &status);
	if (status == 1)
	{
		ft_printf_fd(1, "KO\n");
		return (1);
	}
	else if (status == 2)
	{
		ft_printf_fd(1, "OK\n");
		return (1);
	}
	return (0);
}
