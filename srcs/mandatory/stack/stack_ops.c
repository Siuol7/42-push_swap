/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:28:31 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/25 14:38:37 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		pop_stack(t_stack *stack)
{
	int	res;

	if (!stack || !stack->top || !stack->bottom)
		return (-1);
	if (stack->size == 1)
	{
		res = 
	}
}

void	insert_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
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
	return ;
}
