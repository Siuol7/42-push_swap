/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:27 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/27 14:38:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort3(t_pushswap * ps)
{
	int	top;
	int mid;
	int bot;

	bot = ps->stack_a->top->val;
	mid = ps->stack_a->top->prev->val;
	top = ps->stack_a->bottom->val;
	if (bot > mid && bot > top && mid < top)
		rra(ps);
	else if (bot > mid && bot > top && mid > top)
	{
		ra(ps);
		sa(ps);
	}
	else if (mid > bot && mid > top && top > bot)
		sa(ps);
	else if (mid > bot && mid > top && top < bot)
		ra(ps);
	else if (top > bot && bot > mid)
	{
		rra(ps);
		sa(ps);
	}
}
