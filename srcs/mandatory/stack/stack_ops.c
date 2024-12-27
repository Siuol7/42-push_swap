/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:28:31 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/26 17:23:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*pop_stack(t_stack *stack)
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

int	 insert_node(t_stack *stack, t_node *node)
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
