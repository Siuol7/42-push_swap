/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 16:36:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**digit_parsing(int len, char **av)
{
	int		i;
	int		j;
	char	**final;
	char	**temp;

	i = 0;
	final = malloc((len + 1)*sizeof(char *));
	if (!final)
		return (NULL);
	final[len] = NULL;
	while (i < len)
	{
		j = 0;
		temp = ft_split_allspace(*av);
		if (!*temp)
		{
			ft_free_process_2d(final, i - 1);
			return (NULL);
		}
		while (temp[j])
			final[i++] = ft_strdup(temp[j++]);
		ft_free_2d((void **)temp);
		av++;
	}
	return (final);
}

int	*number_parsing(int len, char **av)
{
	int		*array;
	char	**final;
	int		i;

	i = 0;
	final = digit_parsing(len, av);
	array = (int *)malloc(len * sizeof(int));
	while (final[i])
	{
		if (!ft_isint(final[i]))
			return (NULL);
		array[i] = ft_atoi(final[i]);
		i++;
	}
	return (array);
}
