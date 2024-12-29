/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 11:43:37 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_chunk_number(int size)
{
	(void) size;
	return (13);
}

static int	valid(t_chunk chunk_id, t_node *node)
{
	if (chunk_id.left > node->id  && node->id > chunk_id.right)
		return (0);
	else
	{
		if (node->id > chunk_id.mid)
			return (1);
		else
			return (2);
	}
}

static void	pushing(int size, t_chunk chunk_id, t_pushswap *ps)
{
	t_node	*temp;
	int		status;

	while (size--)
	{
		temp = ps->stack_a->top;
		status = valid(chunk_id, temp->id);
		if (!status)
			ra(ps);
		else if (status == 1)
			pb(ps);
		else
		{
			pb(ps);
			rb(ps);
		}
	}
}

void	a2b(t_pushswap *ps, int size)
{
	t_chunk	chunk_id;
	int		times;
	int		chunk_size;

	ft_memset(&chunk_id, size / 2, sizeof(chunk_id));
	chunk_size = size / get_chunk_number(size);
	times = get_chunk_number(size) / 2;
	while (times--)
	{
		chunk_id.left -= chunk_size;
		chunk_id.right += chunk_size;
		if (times == 1)
		{
			chunk_id.left = 0;
			chunk_id.right = size - 3;
		}
		pushing(size, chunk_id, ps);
	}
	sort3(ps);
}
