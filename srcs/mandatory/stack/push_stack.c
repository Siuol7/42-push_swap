/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:37:54 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/25 11:53:40 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*stack_generating(int *rank, int *main_arr, int size)
{
	int		i;
	t_stack	*stack_a;
	t_node	*node;

	i = size;
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	while (i--)
	{
		node = ft_calloc(1, sizeof(t_node));
		if (!node)
			return (NULL);
		node->val = main_arr[i];
		node->id = get_index(rank, main_arr[i], 0, size);
		if (node->id == -1)
			return (NULL);
		insert_node(stack_a, node);
	}
	return (stack_a);
}

int	push_stack(t_pushswap *ps, int *rank, int *main_arr, int size)
{
	ps->stack_a = stack_generating(rank, main_arr, size);
	if (!ps->stack_a)
		return (0);
	ps->stack_b = ft_calloc(1, sizeof(t_stack));
	if (!ps->stack_b)
		return (0);
	return (1);
}