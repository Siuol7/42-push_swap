/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 13:05:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 1)
		return (0);
	node = pop_stack(stack);
	if (!node)
		return (0);
	node->next = stack->bottom;
	stack->bottom->prev = node;
	stack->bottom = node;
	stack->size++;
	return (1);
}

void	ra(t_pushswap *ps)
{
	if (rotate(ps->stack_a))
		ft_printf_fd(1, "ra\n");
}

void	rb(t_pushswap *ps)
{
	if (rotate(ps->stack_b))
		ft_printf_fd(1, "rb\n");
}
