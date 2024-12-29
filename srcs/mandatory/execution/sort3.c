/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:27 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 14:12:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort3(t_pushswap * ps)
{
	int	top;
	int mid;
	int bot;

	top = ps->stack_a->top->val;
	mid = ps->stack_a->top->prev->val;
	bot = ps->stack_a->bottom->val;
	if (bot > mid && bot > top && mid < top)
		sa(ps);
	else if (mid > bot && mid > top && top > bot)
		rra(ps);
	else if (mid > bot && mid > top && top < bot)
	{
		rra(ps);
		sa(ps);
	}
	else if (top > bot && bot > mid)
		ra(ps);
	else if (top > bot && top > mid && mid > bot)
	{
		ra(ps);
		sa(ps);
	}
}
