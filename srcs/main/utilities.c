/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/31 02:14:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	error_return(int *rank, int *main_arr)
{
	free(rank);
	free(main_arr);
	return (0);
}

int	utilities(int ac, char **av)
{
	t_pushswap	ps;
	int			vector_size;
	int			*rank;
	int			*main_arr;

	(void)ac;
	rank = parsing(av + 1, &vector_size);
	main_arr = parsing(av + 1, &vector_size);
	if (!rank || vector_size == 0 || !main_arr)
		return (error_return(rank, main_arr));
	if (!mergesort(&rank, 0, vector_size - 1))
		return (error_return(rank, main_arr));
	if (!push_stack(&ps, rank, main_arr, vector_size))
		return (error_return(rank, main_arr));
	a2b(&ps, vector_size);
	b2a(&ps);
	clean_stack(&ps);
	free(rank);
	free(main_arr);
	return (1);
}
