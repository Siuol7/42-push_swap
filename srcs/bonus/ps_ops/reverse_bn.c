/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 00:19:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	reverse(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (0);
	node = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	if (!insert_node_bn(stack, node))
		return (0);
	stack->size--;
	return (1);
}

int	rra_bn(t_pushswap *ps)
{
	return (!reverse(ps->stack_a));
}

int	rrb_bn(t_pushswap *ps)
{
	return (!reverse(ps->stack_b));
}

int	rrr_bn(t_pushswap *ps)
{
	if (!reverse(ps->stack_a) || !reverse(ps->stack_b))
		return (0);
	return (1);
}
