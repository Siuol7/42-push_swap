/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 15:15:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = pop_stack_bn(stack);
	if (!node)
		return ;
	node->next = stack->bottom;
	stack->bottom->prev = node;
	stack->bottom = node;
	stack->size++;
}

void	ra_bn(t_pushswap *ps)
{
	rotate(ps->stack_a);
}

void	rb_bn(t_pushswap *ps)
{
	rotate(ps->stack_b);
}

void	rr_bn(t_pushswap *ps)
{
	rotate(ps->stack_a);
	rotate(ps->stack_b);
}
