/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 00:01:11 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pb_bn(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack_bn(ps->stack_a);
	return (insert_node_bn(ps->stack_b, temp));
}

int	pa_bn(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack_bn(ps->stack_b);
	return (insert_node_bn(ps->stack_a, temp));
}
