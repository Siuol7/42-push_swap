/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:44 by hitran            #+#    #+#             */
/*   Updated: 2024/12/31 03:48:25 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target(t_stack *stack, int target)
{
	int		top_down;
	int		bottom_up;
	t_node	*node;

	top_down = 0;
	bottom_up = 1;
	node = stack->top;
	while (node && node->id != target)
	{
		node = node->prev;
		top_down++;
	}
	node = stack->bottom;
	while (node && node->id != target)
	{
		node = node->next;
		bottom_up++;
	}
	if (bottom_up <= top_down)
		return (bottom_up * -1);
	return (top_down);
}

static void	pushing(t_pushswap *ps, int steps)
{
	if (steps < 0)
	{
		steps = -steps;
		while (steps--)
			rrb(ps);
	}
	else if (steps > 0)
	{
		while (steps > 1)
		{
			rb(ps);
			steps--;
		}
		if (steps == 1)
			sb(ps);
	}
	pa(ps);
}

void	b2a(t_pushswap *ps)
{
	int	target;
	int	steps;

	while (ps->stack_b->size > 0)
	{
		target = ps->stack_b->size - 1;
		steps = find_target(ps->stack_b, target);
		pushing(ps, steps);
	}
}
