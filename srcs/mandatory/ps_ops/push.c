/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:05 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/25 17:16:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	pb(t_pushswap *ps)
{
	t_node	*temp;

	if (!ps)
		return (0);
	temp = pop_stack(ps->stack_a);
	if (!temp)
		return (0);
	if(!insert_node(ps->stack_b, temp))
		return (0);
	return (1);
}

int	pa(t_pushswap *ps)
{
	t_node	*temp;

	if (!ps)
		return (0);
	temp = pop_stack(ps->stack_b);
	if (!temp)
		return (0);
	if(!insert_node(ps->stack_a, temp))
		return (0);
	return (1);
}
