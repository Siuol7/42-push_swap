/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:58:35 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 19:21:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fillright(int **array, int *R, t_sort *index)
{
	while (index->j < index->n2)
	{
		(*array)[index->k] = R[index->j];
		index->j++;
		index->k++;
	}
}

static void	fillleft(int **array, int *L, t_sort *index)
{
	while (index->i < index->n1)
	{
		(*array)[index->k] = L[index->i];
		index->i++;
		index->k++;
	}
}

static void	merge(int **array, int *L, int *R, t_sort *index)
{
	index->i = 0;
	index->j = 0;
	while (index->i < index->n1 && index->j < index->n2)
	{
		if (L[index->i] == R[index->j])
			index->dup = 1;
		if (L[index->i] <= R[index->j])
		{
			(*array)[index->k] = L[index->i];
			index->i++;
			index->k++;
		}
		else
		{
			(*array)[index->k] = R[index->j];
			index->j++;
			index->k++;
		}
	}
	fillleft(array, L, index);
	fillright(array, R, index);

}

static int	premerge(int **array, int left, int mid, int right)
{
	t_sort index;
	int		*L;
	int		*R;

	ft_bzero(&index, sizeof(index));
	index.n1 = mid - left + 1;
	index.n2 = right - mid;
	L = (int *)malloc(index.n1 * sizeof(int));
	R = (int *)malloc(index.n2 * sizeof(int));
	while (index.i < index.n1)
	{
		L[index.i] = (*array)[left + index.i];
		index.i++;
	}
	while (index.j < index.n2)
	{
		R[index.j] = (*array)[mid + 1 + index.j];
		index.j++;
	}
	index.k = left;
	merge(array, L, R, &index);
	free(L);
	free(R);
	if (index.dup == 1)
		return (0);
	return (1);
}

int	mergesort(int **array, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (right + left) / 2;
		mergesort(array, left, mid);
		mergesort(array, mid + 1, right);
		if (premerge(array, left, mid, right))
			return (0);
	}
	return (1);
}
