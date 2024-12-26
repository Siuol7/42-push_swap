/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:16 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/26 06:00:21 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = pop_stack(stack);
	node2 = pop_stack(stack);
	if (!insert_node(stack, node1))
		return (0);
	if (!insert_node(stack, node2))
		return (0);
	return (1);
}

void	sa(t_pushswap	*ps)
{
	if (!swap(ps->stack_a))
		ft_printf_fd(1, "Error\n");
	ft_printf_fd(1, "sa\n");
}

void	sb(t_pushswap	*ps)
{
	if (!swap(ps->stack_b))
		ft_printf_fd(1, "Error\n");
	ft_printf_fd(1, "sa\n");
}

void	ss(t_pushswap	*ps)
{
	if (!swap(ps->stack_a))
		ft_printf_fd(1, "Error\n");
	if (!swap(ps->stack_b))
		ft_printf_fd(1, "Error\n");
	ft_printf_fd(1, "ss\n");
}
