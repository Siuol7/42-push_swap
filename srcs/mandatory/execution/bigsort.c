/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:18:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/28 17:47:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_chunk_no(int size)
{
}

static int	valid(int turn, int size, t_node *node)
{
	if (turn == 1 && (0 <= node->id && node->id <= size))
		return (1);
	else if (size * turn + 1  <= node->id
		&& node->id <= size * (turn + 1));
		return (1);
	return (0);
}

static int	get_pos(int turn, int size, t_stack *stack_a)
{
	int		bottom_up;
	int		top_down;
	t_node	*node;

	bottom_up = 0;
	top_down = 0;
	node = stack_a->top;
	while (node->prev && !valid(turn, size, node))
	{
		node = node->prev;
		top_down++;
	}
	node = stack_a->bottom;
	while (node->next && !valid(turn, size, node))
	{
		node = node->next;
		bottom_up++;
	}
	if (bottom_up < top_down)
		return (bottom_up * -1);
	return (top_down);
}

static void	pushing(int turn, int chunk_size, int chunk_no, t_pushswap *ps)
{
	int	times;
	int	i;

	while (turn < chunk_no)
	{
		i = -1;
		while (++i < chunk_size)
		{
			times = get_pos(turn, chunk_size, ps->stack_a);
			if (times < 0)
			{
				times = -times;
				while (times--)
					rra(ps);
			}
			else
			{
				while (times--)
					ra(ps);
			}
			pb(ps);
		}
		turn++;
	}
}

void	a2b(t_pushswap *ps, int size)
{
	int	chunk_no;
	int	chunk_size;
	int	i;

	i = 0;
	chunk_no = get_chunk_no(size);
	chunk_size = size / chunk_no;
	pushing(0, chunk_size, chunk_no, ps);
}