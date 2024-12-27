/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:29:05 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/26 18:13:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pb(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack(ps->stack_a);
	if (insert_node(ps->stack_b, temp))
		ft_printf_fd(1, "pb\n");
}

void	pa(t_pushswap *ps)
{
	t_node	*temp;

	temp = pop_stack(ps->stack_b);
	if (insert_node(ps->stack_a, temp))
		ft_printf_fd(1, "pa\n");
}
