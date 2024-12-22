/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 05:30:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**number_parsing(int len, char **av)
{
	int		i;
	int		j;
	char	**final;
	char	**temp;

	i = 0;
	final = malloc(len + 1);
	if (!final)
		return (NULL);
	final[len] = NULL;
	while (i < len)
	{
		j = 0;
		temp = ft_split(av);
		if (!*temp)
		{
			ft_free_process_2d(final, i - 1);
			return (NULL);
		}
		while (*temp)
			final[i++] = ft_strdup(temp[j++]);
		ft_free_2d(temp);
		av++;
	}
	return (final);
}
