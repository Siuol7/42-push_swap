/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:58:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:33:56 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	fillright(int **array, int *R, t_sort *id)
{
	while (id->j < id->n2)
	{
		(*array)[id->k] = R[id->j];
		id->j++;
		id->k++;
	}
}

static void	fillleft(int **array, int *L, t_sort *id)
{
	while (id->i < id->n1)
	{
		(*array)[id->k] = L[id->i];
		id->i++;
		id->k++;
	}
}

static void	merge(int **array, int *L, int *R, t_sort *id)
{
	id->i = 0;
	id->j = 0;
	while (id->i < id->n1 && id->j < id->n2)
	{
		if (L[id->i] == R[id->j])
			id->dup = 1;
		if (L[id->i] <= R[id->j])
		{
			(*array)[id->k] = L[id->i];
			id->i++;
			id->k++;
		}
		else
		{
			(*array)[id->k] = R[id->j];
			id->j++;
			id->k++;
		}
	}
	fillleft(array, L, id);
	fillright(array, R, id);
}

static int	premerge(int **array, int left, int mid, int right)
{
	t_sort	id;
	int		*l;
	int		*r;

	ft_bminus(&id, sizeof(id));
	id.n1 = mid - left + 1;
	id.n2 = right - mid;
	l = (int *)malloc(id.n1 * sizeof(int));
	r = (int *)malloc(id.n2 * sizeof(int));
	while (++id.i < id.n1)
		l[id.i] = (*array)[left + id.i];
	while (++id.j < id.n2)
		r[id.j] = (*array)[mid + 1 + id.j];
	id.k = left;
	merge(array, l, r, &id);
	free(l);
	free(r);
	if (id.dup == 1)
		return (0);
	return (1);
}

int	mergesort_bn(int **array, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (right + left) / 2;
		mergesort(array, left, mid);
		mergesort(array, mid + 1, right);
		if (!premerge(array, left, mid, right))
			return (0);
	}
	return (1);
}
