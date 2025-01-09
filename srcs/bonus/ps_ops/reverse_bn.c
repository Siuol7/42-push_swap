/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:44:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	reverse(t_stack *stack)
{
	t_node	*node;

	node = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	if (!insert_node_bn(stack, node))
		return (0);
	stack->size--;
	return (1);
}

void	rra_bn(t_pushswap *ps)
{
	if (reverse(ps->stack_a))
		ft_printf_fd(1, "rra\n");
}

void	rrb_bn(t_pushswap *ps)
{
	if (reverse(ps->stack_b))
		ft_printf_fd(1, "rrb\n");
}

void	rrr_bn(t_pushswap *ps)
{
	if (reverse(ps->stack_a) && reverse(ps->stack_b))
		ft_printf_fd(1, "rrs\n");
}
