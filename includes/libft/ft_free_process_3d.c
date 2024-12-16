/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_process_3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:33:38 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/11 07:16:40 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_process_3d(char ***arr, size_t cur)
{
	if (!(*arr)[cur])
	{
		while (cur-- > 0)
		{
			free((*arr)[cur]);
			(*arr[cur]) = NULL;
		}
		free(*arr);
		(*arr) = NULL;
		return (0);
	}
	return (1);
}