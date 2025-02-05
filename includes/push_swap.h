/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:00:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 13:06:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/ft_printf_fd/ft_printf.h"
# include "../library/libft/libft.h"

typedef struct s_sort
{
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;
	int	dup;
}	t_sort;

typedef struct s_chunk
{
	int	left;
	int	right;
	int	mid;
}	t_chunk;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
	int				id;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		steps;
}	t_pushswap;

//ERROR
//error_parsing
void	error_parsing(char **a, char **b);

//PARSING
//parsing
int		*parsing(char **av, int *size);

//number parsing
int		*number_parsing(int len, char **av);

//utils
int		number_count(char **av);
int		check_duplicate(int *rank, int size);
int		compare(int *rank, int *main_arr, int size);

//pre push_swap
int		mergesort(int **array, int left, int right);

//STACKING
//push_stack
int		push_stack(t_pushswap *ps, int *rank, int *main_arr, int size);

//stack_ops
int		insert_node(t_stack *stack, t_node *node);
t_node	*pop_stack(t_stack *stack);
void	clean_stack(t_pushswap *ps);

//utils
int		get_id(int *rank, int val, int left, int right);

//PS_OPS
//push
void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);

//swap
void	sb(t_pushswap	*ps);
void	sa(t_pushswap	*ps);

//reverse
void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);

//rotate
void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);

//EXECUTION
//sort3
void	sort3(t_pushswap *ps);

//bigsort
void	a2b(t_pushswap *ps, int size);
void	b2a(t_pushswap *ps);

//MAIN
int		utilities(char **av);

#endif