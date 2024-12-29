/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 17:31:20 by caonguye         ###   ########.fr       */
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
		return(error_return(rank, main_arr));

	// ps.steps = 0;
	// ft_printf_fd(1, "before\n");
	// t_node	*temp;
	// temp = ps.stack_a->top;
	// ft_printf_fd(1, "Stack A\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }
	// temp = ps.stack_b->top;
	// ft_printf_fd(1, "\nStack B\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }
	//sort5(&ps);
	a2b(&ps, vector_size);
	// ft_printf_fd(1, "\nafter\n");
	// temp = ps.stack_a->top;
	// ft_printf_fd(1, "Stack A\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }
	// temp = ps.stack_b->top;
	// ft_printf_fd(1, "\nStack B\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }

	b2a(&ps, vector_size);
	// ft_printf_fd(1, "\nafter\n");
	// temp = ps.stack_a->top;
	// ft_printf_fd(1, "Stack A\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }
	// temp = ps.stack_b->top;
	// ft_printf_fd(1, "\nStack B\n");
	// while (temp)
	// {
	// 	ft_printf_fd(1, "id-%d: val-%d\n", temp->id, temp->val);
	// 	temp = temp->prev;
	// }

	free(rank);
	free(main_arr);
	return (1);
}
