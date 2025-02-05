/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_bn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:28:31 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 08:49:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clear_stack(t_pushswap *ps)
{
	t_node	*node;

	while (ps->stack_a->top)
	{
		node = ps->stack_a->top;
		ps->stack_a->top = ps->stack_a->top->prev;
		free(node);
	}
	free(ps->stack_a);
	while (ps->stack_b->top)
	{
		node = ps->stack_b->top;
		ps->stack_b->top = ps->stack_b->top->prev;
		free(node);
	}
	free(ps->stack_b);
}

t_node	*pop_stack_bn(t_stack *stack)
{
	t_node	*res;

	if (!stack || !stack->top || !stack->bottom)
		return (NULL);
	if (stack->size == 1)
	{
		res = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		res = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = NULL;
		res->prev = NULL;
	}
	stack->size--;
	return (res);
}

int	insert_node_bn(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return (0);
	if (stack->top == 0 && stack->bottom == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = stack->top->next;
	}
	stack->size++;
	return (1);
}
