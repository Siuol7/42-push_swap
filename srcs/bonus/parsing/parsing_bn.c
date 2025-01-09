/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 06:40:42 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*parsing_bn(char **av, int *size)
{
	int		len;
	int		*array;

	len = number_count(av);
	*size = len;
	array = number_parsing(len, av);
	if (!array)
		return (NULL);
	return (array);
}
