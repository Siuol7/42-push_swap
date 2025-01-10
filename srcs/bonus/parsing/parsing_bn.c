/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 09:50:12 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*parsing_bn(char **av, int *size)
{
	int		len;
	int		*array;

	len = number_count_bn(av);
	*size = len;
	array = number_parsing_bn(len, av);
	if (!array)
		return (NULL);
	return (array);
}
