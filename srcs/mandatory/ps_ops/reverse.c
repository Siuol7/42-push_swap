/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/26 08:34:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	reverse(t_stack *stack)
{
	t_node	*node;

	node = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	insert_node(stack, node);
}

void	rra(t_pushswap *ps)
{
	reverse(ps->stack_a);
}

void	rrb(t_pushswap *ps)
{
	reverse(ps->stack_b);
}

void	rrs(t_pushswap *ps)
{
	reverse(ps->stack_a);
	reverse(ps->stack_b);
}

