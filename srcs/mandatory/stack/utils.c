/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:13:02 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/28 19:54:00 by caonguye         ###   ########.fr       */
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
	return (-1);
}
