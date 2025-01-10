/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 08:33:22 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = pop_stack_bn(stack);
	node2 = pop_stack_bn(stack);
	if (!insert_node_bn(stack, node1))
		return (0);
	if (!insert_node_bn(stack, node2))
		return (0);
	return (1);
}

void	sa_bn(t_pushswap	*ps)
{
	swap(ps->stack_a);
}

void	sb_bn(t_pushswap	*ps)
{
	swap(ps->stack_b);
}

void	ss_bn(t_pushswap	*ps)
{
	swap(ps->stack_a);
	swap(ps->stack_b);
}
