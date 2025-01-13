/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 00:19:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (0);
	node = pop_stack_bn(stack);
	if (!node)
		return (0);
	node->next = stack->bottom;
	stack->bottom->prev = node;
	stack->bottom = node;
	stack->size++;
	return (1);
}

int	ra_bn(t_pushswap *ps)
{
	return (rotate(ps->stack_a));
}

int	rb_bn(t_pushswap *ps)
{
	return (rotate(ps->stack_b));
}

int	rr_bn(t_pushswap *ps)
{
	if (!rotate(ps->stack_a) || !rotate(ps->stack_b))
		return (0);
	return (1);
}
