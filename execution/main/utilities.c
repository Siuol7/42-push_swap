/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/24 10:11:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_return(int *rank)
{
	free(rank);
	return (0);
}

int	utilities(int ac, char **av)
{
	//t_pushswap	ps;
	int			vector_size;
	int			*rank;
	// int		*main_arr;

	(void)ac;
	rank = parsing(++av, &vector_size);
	if (!rank || vector_size == 0)
		return (error_return(rank));
	if (!mergesort(&rank, 0, vector_size - 1))
		return (error_return(rank));
	int i = 0;
	while (i < vector_size)
		ft_printf_fd(1, "\n%d", rank[i++]);
	free(rank);
	return (1);
}
