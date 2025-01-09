/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:13:02 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:55:26 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	get_id_bn(int *rank, int val, int left, int right)
{
	int	mid;

	if (left > right)
		return (-1);
	mid = (left + right) / 2;
	if (rank[mid] == val)
		return (mid);
	if (val < rank[mid])
		return (get_id(rank, val, left, mid - 1));
	if (val > rank[mid])
		return (get_id(rank, val, mid + 1, right));
	return (-1);
}
