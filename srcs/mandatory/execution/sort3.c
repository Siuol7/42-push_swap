/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:27 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/27 08:45:33 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>>

void	sort3(t_pushswap * ps)
{
	int	top;
	int mid;
	int bot;

	top = ps->stack_a->top->val;
	mid = ps->stack_a->top->prev->val;
	bot = ps->stack_a->bottom->val;
	if (bot > mid && bot > top)
	{
		if (mid < top)
			rra(ps);
		ra(ps);
		sa(ps);
	}
	else if (mid > bot && mid > top)
	{
		if (top > bot)
			sa(ps);
		ra(ps);
	}
	else if (top > bot && bot > mid)
	{
		rra(ps);
		sa(ps);
	}
}
