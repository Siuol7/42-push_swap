/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:01:25 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/08 15:56:57 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_parsing(char **a, char **b)
{
	ft_free_2d((void **)a);
	ft_free_2d((void **)b);
	ft_printf_fd(2, "Error\n");
}
