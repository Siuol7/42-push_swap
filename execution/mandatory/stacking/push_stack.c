/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:37:54 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/23 09:59:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_index(int *rank, int val, int left, int right)
{
	int	mid;

	if (left > right)
		return (-1);
	mid = (left + right) / 2;
	if (rank[mid] == val)
		return (mid);
	if (val < rank[mid])
		return (get_index(rank, val, left, mid - 1));
	if (val > rank[mid])
		return (get_index(rank, val, mid + 1, right));
}