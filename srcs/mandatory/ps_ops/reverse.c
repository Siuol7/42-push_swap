/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 00:07:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	reverse(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 1)
		return (0);
	node = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	if (!insert_node(stack, node))
		return (0);
	stack->size--;
	return (1);
}

void	rra(t_pushswap *ps)
{
	if (reverse(ps->stack_a))
		ft_printf_fd(1, "rra\n");
}

void	rrb(t_pushswap *ps)
{
	if (reverse(ps->stack_b))
		ft_printf_fd(1, "rrb\n");
}

void	rrr(t_pushswap *ps)
{
	if (reverse(ps->stack_a) && reverse(ps->stack_b))
		ft_printf_fd(1, "rrr\n");
}
