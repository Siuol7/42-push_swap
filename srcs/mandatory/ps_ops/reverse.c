/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/27 15:25:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	reverse(t_stack *stack)
{
	t_node	*node;

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
		ft_printf_fd(1,"rrb\n");
}

void	rrs(t_pushswap *ps)
{
	if (reverse(ps->stack_a) && reverse(ps->stack_b))
		ft_printf_fd(1, "rrs\n");
}

