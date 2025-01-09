/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:44:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	rotate(t_stack *stack)
{
	t_node	*node;

	node = pop_stack_bn(stack);
	if (!node)
		return (0);
	node->next = stack->bottom;
	stack->bottom->prev = node;
	stack->bottom = node;
	stack->size++;
	return (1);
}

void	ra_bn(t_pushswap *ps)
{
	if (rotate(ps->stack_a))
		ft_printf_fd(1, "ra\n");
}

void	rb_bn(t_pushswap *ps)
{
	if (rotate(ps->stack_b))
		ft_printf_fd(1, "rb\n");
}

void	rr_bn(t_pushswap *ps)
{
	if (rotate(ps->stack_a) && rotate(ps->stack_b))
		ft_printf_fd(1, "rr\n");
}
