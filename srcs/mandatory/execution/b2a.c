/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:17:58 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 01:44:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int find_correct_position(t_stack *stack_a, int value)
{
    if (!stack_a || !stack_a->top)
        return 0;

    t_node *current = stack_a->top;
    int pos = 0;

    while (current && current->val < value)
    {
        current = current->next;
        pos++;
    }

    return pos;
}

static int find_min_value(t_stack *stack_a)
{
    if (!stack_a || !stack_a->top)
        return 0;

    t_node *current = stack_a->top;
    int min_value = current->val;

    while (current)
    {
        if (current->val < min_value)
            min_value = current->val;
        current = current->next;
    }

    return min_value;
}

void b2a(t_pushswap *ps, int size)
{
    if (!ps || !ps->stack_a || !ps->stack_b || !ps->stack_b->top)
        return;
    while (size-- && ps->stack_b->top)
    {
        t_node *temp = ps->stack_b->top;

        int pos = find_correct_position(ps->stack_a, temp->val);

        if (pos < ps->stack_a->size / 2)
        {
            while (pos-- > 0)
                ra(ps);
        }
        else
        {
            while (ps->stack_a->size - pos-- > 0)
                rra(ps);
        }
        pa(ps);
    }
    if (ps->stack_a && ps->stack_a->top)
    {
        int min_value = find_min_value(ps->stack_a);
        while (ps->stack_a->top->val != min_value)
            ra(ps);
    }
}
