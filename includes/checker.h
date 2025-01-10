/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:18:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 09:50:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../library/ft_printf_fd/ft_printf.h"
# include "../library/libft/libft.h"
# include <fcntl.h>

typedef struct s_sort
{
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;
	int	dup;
}	t_sort;

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
void	error_parsing_bn(char **a, char **b);

//PARSING
//parsing
int		*parsing_bn(char **av, int *size);

//number parsing
int		*number_parsing_bn(int len, char **av);

//utils
int		number_count_bn(char **av);
int		check_duplicate_bn(int *rank, int size);
int		compare_bn(int *rank, int *main_arr, int size);

//pre push_swap
int		mergesort_bn(int **array, int left, int right);

//STACKING
//push_stack
int		push_stack_bn(t_pushswap *ps, int *rank, int *main_arr, int size);

//stack_ops
int		insert_node_bn(t_stack *stack, t_node *node);
t_node	*pop_stack_bn(t_stack *stack);
void	clear_stack(t_pushswap *ps);

//utils
int		get_id_bn(int *rank, int val, int left, int right);

//PS_OPS
//push
void	pa_bn(t_pushswap *ps);
void	pb_bn(t_pushswap *ps);

//swap
void	ss_bn(t_pushswap	*ps);
void	sb_bn(t_pushswap	*ps);
void	sa_bn(t_pushswap	*ps);

//reverse
void	rra_bn(t_pushswap *ps);
void	rrb_bn(t_pushswap *ps);
void	rrr_bn(t_pushswap *ps);

//rotate
void	ra_bn(t_pushswap *ps);
void	rb_bn(t_pushswap *ps);
void	rr_bn(t_pushswap *ps);

//MAIN
int		checker(char **av);

//EXECUTION
int		read_and_exec(t_pushswap *ps);

#endif