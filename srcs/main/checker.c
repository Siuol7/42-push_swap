/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:58:41 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 08:49:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	error_return_bn(int *rank, int *main_arr)
{
	free(rank);
	free(main_arr);
	return (0);
}

static int	ops_execute(t_pushswap ps)
{
	if (ps.stack_a->size == 2
		&& (ps.stack_a->top->id > ps.stack_a->bottom->id))
		sa_bn(&ps);
	else if (ps.stack_a->size >= 3)
	{
		if (!read_and_exec(&ps))
			return (0);
	}
	return (1);
}

int	checker(char **av)
{
	t_pushswap	ps;
	int			vector_size;
	int			*rank;
	int			*main_arr;

	rank = parsing_bn(av + 1, &vector_size);
	main_arr = parsing_bn(av + 1, &vector_size);
	if (!rank || vector_size == 0 || !main_arr
		|| !mergesort_bn(&rank, 0, vector_size - 1)
		|| !push_stack_bn(&ps, rank, main_arr, vector_size))
		return (error_return_bn(rank, main_arr));
	if (check_duplicate_bn(rank, ps.stack_a->size))
		return (error_return_bn(rank, main_arr));
	if (compare_bn(rank, main_arr, ps.stack_a->size))
	{
		if (!ops_execute(ps))
			return (0);
	}
	clear_stack(&ps);
	free(rank);
	free(main_arr);
	return (1);
}
