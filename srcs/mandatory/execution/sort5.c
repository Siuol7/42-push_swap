/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:45:13 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/27 13:16:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_lowest(t_stack *stack)
{
	int		min;
	int		pos;
	int		lowest_pos;
	t_node	*temp;

	min = INT_MAX;
	pos = 0;
	temp = stack->bottom;
	while (temp->next)
	{
		if (temp->val < min)
		{
			min = temp->val;
			lowest_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (lowest_pos + 1);
}

void	sort5(t_pushswap *ps)
{
	int	lowest_pos;

	if (ps->stack_a->size == 3)
	{
		sort3(ps);
		return ;
	}
	lowest_pos = get_lowest(ps->stack_a);
	if (lowest_pos <= (ps->stack_a->size / 2))
	{
		while (lowest_pos--)
			rra(ps);
	}
	else
	{
		lowest_pos = ps->stack_a->size - lowest_pos;
		while (lowest_pos--)
			ra(ps);
	}
	pb(ps);
	sort5(ps);
	pa(ps);
}
