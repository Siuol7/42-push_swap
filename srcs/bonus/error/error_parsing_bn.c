/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing_bn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:01:25 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:54:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	error_parsing(char **a, char **b)
{
	ft_free_2d((void **)a);
	ft_free_2d((void **)b);
	ft_printf_fd(2, "Error\n");
}
