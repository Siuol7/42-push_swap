/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/13 17:33:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_malloc(int *array, char **final)
{
	if (!array)
	{
		ft_free_2d((void **)final);
		return (0);
	}
	return (1);
}

static int	process_temp(char **temp, char **final, int *i)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		final[*i] = ft_strdup(temp[j]);
		if (!final[*i])
		{
			ft_free_2d((void **)temp);
			ft_free_process_2d(final, *i);
			return (0);
		}
		(*i)++;
		j++;
	}
	return (1);
}

static char	**digit_parsing(int len, char **av)
{
	int		i;
	char	**final;
	char	**temp;

	i = 0;
	final = malloc((len + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	final[len] = NULL;
	while (i < len)
	{
		temp = ft_split_allspace(*av++);
		if (!temp)
		{
			ft_free_process_2d(final, i);
			return (NULL);
		}
		if (!process_temp(temp, final, &i))
			return (NULL);
		ft_free_2d((void **)temp);
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
	if (!final)
		return (NULL);
	array = (int *)malloc(len * sizeof(int));
	if (!check_malloc(array, final))
		return (NULL);
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
