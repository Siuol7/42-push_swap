/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:44:26 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	pb_bn(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack_bn(ps->stack_a);
	if (insert_node_bn(ps->stack_b, temp))
		ft_printf_fd(1, "pb\n");
}

void	pa_bn(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack_bn(ps->stack_b);
	if (insert_node_bn(ps->stack_a, temp))
		ft_printf_fd(1, "pa\n");
}
