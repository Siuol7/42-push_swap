/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/24 09:34:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*parsing(char **av, int *size)
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
