/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing_bn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/13 00:40:42 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_malloc(int *array, char **final)
{
	if (!array)
	{
		ft_free_2d(final);
		return (NULL);
	}
}

static void	check_proces(char *temp, int i)
{
	if (!temp)
	{
		ft_free_process_2d(temp, i - 1);
		return (NULL);
	}
}

static char	**digit_parsing(int len, char **av)
{
	int		i;
	int		j;
	char	**final;
	char	**temp;

	i = -1;
	final = malloc((len + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	final[len] = NULL;
	while (++i < len)
	{
		j = -1;
		temp = ft_split_allspace(*av++);
		check_process(temp, j)
		while (temp[++j])
		{
			final[i] = ft_strdup(temp[j++]);
			if (!final[i])
				ft_free_process_2d(final, i);
			return (NULL);
		}
		ft_free_2d((void **)temp);
	}
	return (final);
}

int	*number_parsing_bn(int len, char **av)
{
	int		*array;
	char	**final;
	int		i;

	i = 0;
	final = digit_parsing(len, av);
	if (!final)
		return (NULL);
	array = (int *)malloc(len * sizeof(int));
	check_malloc(array, final);
	while (final[i])
	{
		if (!ft_isint(final[i]))
		{
			ft_free_2d((void **)final);
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(final[i]);
		i++;
	}
	ft_free_2d((void **)final);
	return (array);
}
