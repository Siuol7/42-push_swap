/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:00:39 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/23 11:16:34 by caonguye         ###   ########.fr       */
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
	int n1;
	int n2;
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
	t_stack	*a;
	t_stack	*b;
}	t_pushswap;



//ERROR
//error_parsing
void	error_parsing(char **a, char **b);

//PARSING
//parsing
int	*parsing(char **av, int *size);

//number parsing
int		*number_parsing(int len, char **av);

//utils
int		number_count(char **av);

//pre push_swap
int		mergesort(int **array, int left, int right);

int		utilities(int ac, char **av);

#endif