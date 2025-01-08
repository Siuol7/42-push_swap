/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/08 18:40:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	error_return(int *rank, int *main_arr)
{
	free(rank);
	free(main_arr);
	return (0);
}

static void	ops_case(t_pushswap ps)
{
	if (ps.stack_a->size == 2
		&& (ps.stack_a->top->id > ps.stack_a->bottom->id))
		sa(&ps);
	else if (ps.stack_a->size > 3)
	{
		a2b(&ps, ps.stack_a->size);
		b2a(&ps);
	}
	else if (ps.stack_a->size == 3)
		sort3(&ps);
	else
		return ;
}

int	utilities(char **av)
{
	t_pushswap	ps;
	int			vector_size;
	int			*rank;
	int			*main_arr;

	rank = parsing(av + 1, &vector_size);
	main_arr = parsing(av + 1, &vector_size);
	if (!rank || vector_size == 0 || !main_arr
		|| !mergesort(&rank, 0, vector_size - 1)
		|| !push_stack(&ps, rank, main_arr, vector_size))
		return (error_return(rank, main_arr));
	if (check_duplicate(rank, ps.stack_a->size))
		return (error_return(rank, main_arr));
	if (compare(rank, main_arr, ps.stack_a->size))
		ops_case(ps);
	clean_stack(&ps);
	free(rank);
	free(main_arr);
	return (1);
}
