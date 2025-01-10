/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:13:02 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 07:51:33 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_id_bn(int *rank, int val, int left, int right)
{
	int	mid;

	if (left > right)
		return (-1);
	mid = (left + right) / 2;
	if (rank[mid] == val)
		return (mid);
	if (val < rank[mid])
		return (get_id_bn(rank, val, left, mid - 1));
	if (val > rank[mid])
		return (get_id_bn(rank, val, mid + 1, right));
	return (-1);
}

int	ft_issorted(t_pushswap *ps)
{
	t_node *node;

	node = ps->stack_a->top;
	while (node->prev != NULL)
	{
		if (node->id > node->prev->id)
			return (1);
		node = node->prev;
	}
	return (0);
}
