/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:44 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/08 12:55:56 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_chunk_number(int size)
{
	if (size <= 100)
		return (4);
	return (10);
}

static int	valid(t_chunk chunk_id, t_node *node)
{
	if (chunk_id.left > node->id && node->id > chunk_id.right)
		return (0);
	else if (chunk_id.left <= node->id && node->id <= chunk_id.right)
	{
		if (node->id > chunk_id.mid)
			return (1);
		else
			return (2);
	}
	return (0);
}

static void	pushing(int size, t_chunk chunk_id, t_pushswap *ps)
{
	t_node	*temp;
	int		status;

	while (size--)
	{
		temp = ps->stack_a->top;
		status = valid(chunk_id, temp);
		if (!status)
			ra(ps);
		else if (status == 1)
		{
			pb(ps);
			if (ps->stack_b->size > 1
				&& ps->stack_b->top->id < ps->stack_b->top->prev->id)
				sb(ps);
		}
		else
		{
			pb(ps);
			if (ps->stack_b->size > 1)
				rb(ps);
		}
	}
}

void	a2b(t_pushswap *ps, int size)
{
	t_chunk	chunk_id;
	int		times;
	int		chunk_size;

	if (!ps || !ps->stack_a || !ps->stack_b)
		return ;
	chunk_id.left = size / 2;
	chunk_id.right = size / 2;
	chunk_id.mid = size / 2;
	chunk_size = size / get_chunk_number(size);
	times = get_chunk_number(size) / 2;
	while (times)
	{
		chunk_id.left -= chunk_size;
		chunk_id.right += chunk_size;
		if (times == 1)
		{
			chunk_id.left = 0;
			chunk_id.right = size - 4;
		}
		pushing(ps->stack_a->size, chunk_id, ps);
		times--;
	}
	sort3(ps);
}
