/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:44 by caonguye            #+#    #+#             */
/*   Updated: 2025/01/08 11:24:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *stack, int target, int size)
{
	int		position;
	t_node	*node;

	node = stack->top;
	position = 0;
	while (position < size && node)
	{
		if (node->id == target)
			return (position);
		position++;
		node = node->prev;
	}
	return (-1);
}

static int	sort_a(t_pushswap *ps, int *ra_steps, int *rra_steps, int *target)
{
	if (ps->stack_a->size == 0)
		return (0);
	if (ps->stack_a->bottom->id == *target)
	{
		rra(ps);
		(*rra_steps)--;
		(*target)--;
		return (1);
	}
	else if (find_pos(ps->stack_a, *target, *ra_steps) != -1)
	{
		(*ra_steps)--;
		(*target)--;
		return (1);
	}
	return (0);
}

static int	push_target(t_pushswap *ps, int *ra_steps,
				int *rra_steps, int *target)
{
	if (!ps->stack_b->size || *target != ps->stack_b->top->id)
		return (0);
	while (*ra_steps > 1)
	{
		ra(ps);
		(*ra_steps)--;
		(*rra_steps)++;
	}
	pa(ps);
	if (*ra_steps == 1)
		sa(ps);
	(*target)--;
	return (1);
}

static int	pushing(t_pushswap *ps, int *ra_steps, int *rra_steps)
{
	if (!ps->stack_b->size)
		return (0);
	if ((*rra_steps == 0 || ps->stack_b->top->id > ps->stack_a->bottom->id))
	{
		while (*ra_steps && ps->stack_b->top->id > ps->stack_a->top->id)
		{
			ra(ps);
			(*ra_steps)--;
			(*rra_steps)++;
		}
		pa(ps);
		(*ra_steps)++;
		return (1);
	}
	return (0);
}

void	b2a(t_pushswap *ps)
{
	int	ra_steps;
	int	rra_steps;
	int	target;

	ra_steps = 0;
	rra_steps = 0;
	target = ps->stack_b->size - 1;
	while (ps->stack_b->size || ra_steps > 0 || rra_steps > 0)
	{
		if (sort_a(ps, &ra_steps, &rra_steps, &target))
			continue ;
		else if (push_target(ps, &ra_steps, &rra_steps, &target))
			continue ;
		else if (pushing(ps, &ra_steps, &rra_steps))
			continue ;
		else if (find_pos(ps->stack_b, target, ps->stack_b->size) > (ps->stack_b->size / 2))
			rrb(ps);
		else if (find_pos(ps->stack_b, target, ps->stack_b->size) > -1)
			rb(ps);
	}
}
