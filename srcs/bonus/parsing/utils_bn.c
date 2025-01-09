/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:02:29 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:55:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	single_count_bn(char *av)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (av[i])
	{
		while (av[i] == 32 || (9 <= av[i] && av[i] <= 13))
			i++;
		if (av[i] > 32 && av[i] < 127)
			cnt++;
		while ((av[i] > 32 && av[i] < 127))
			i++;
	}
	return (cnt);
}

int	number_count_bn(char **av)
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

int	check_duplicate_bn(int *rank, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (rank[i] == rank[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	compare_bn(int *rank, int *main_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (rank[i] != main_arr[i])
			return (1);
		i++;
	}
	return (0);
}
