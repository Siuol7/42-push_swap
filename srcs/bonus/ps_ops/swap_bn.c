/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 15:16:39 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = pop_stack_bn(stack);
	node2 = pop_stack_bn(stack);
	if (!insert_node_bn(stack, node1))
		return ;
	if (!insert_node_bn(stack, node2))
		return ;
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
