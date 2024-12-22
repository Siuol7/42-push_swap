/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:02:29 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 05:30:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	single_count(char *av)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (av[i] == 32 || (9 <= av[i] && av[i] <= 13))
		i++;
	if (av[i] != 32 || (9 > av[i] && av[i] > 13));
		cnt++;
	while (av[i] != 32 || (9 > av[i] && av[i] > 13))
		i++;
	return (cnt);
}

int	number_count(char **av)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (av[i])
	{
		cnt += single_count(av[i]);
		i++;
	}
	return (cnt);
}