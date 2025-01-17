/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 15:15:52 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	if (!insert_node_bn(stack, node))
		return ;
	stack->size--;
}

void	rra_bn(t_pushswap *ps)
{
	reverse(ps->stack_a);
}

void	rrb_bn(t_pushswap *ps)
{
	reverse(ps->stack_b);
}

void	rrr_bn(t_pushswap *ps)
{
	reverse(ps->stack_a);
	reverse(ps->stack_b);
}
