/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:17:58 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 18:45:33 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_pos(t_stack *stack, int id)
{
	t_node	*temp;
	int		times;

	temp = stack->top;
	times = 0;
	while (temp->prev && temp->id != id + 1)
	{
		temp = temp->prev;
		times++;
	}
	if (temp->id != id + 1)
		return (-1);
	return (times);
}

void	b2a(t_pushswap *ps, int size)
{
	t_node	*temp;
	int		times;
	int		i;

	while (size--)
	{
		if (ps->stack_b->top->id < ps->stack_b->top->prev->id)
			sb(ps);
		temp = ps->stack_b->top;
		times = find_pos(ps->stack_a, temp->id);
		if (times < 0)
			pa(ps);
		else
		{
			i = times;
			while (i--)
				ra(ps);
			pa(ps);
			while (times--)
				rra(ps);
		}
	}
}
