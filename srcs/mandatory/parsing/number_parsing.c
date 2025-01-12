/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:59:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/13 00:40:58 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_malloc(int *array, char **final)
{
	if (!array)
	{
		ft_free_2d(final);
		return (NULL);
	}
}

static char	**digit_parsing(int len, char **av)
{
	int		i;
	int		j;
	char	**final;
	char	**temp;

	i = 0;
	final = malloc((len + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	final[len] = NULL;
	while (i < len)
	{
		j = 0;
		temp = ft_split_allspace(*av);
		if (!temp)
		{
			ft_free_process_2d(final, i - 1);
			return (NULL);
		}
		while (temp[j])
			final[i++] = ft_strdup(temp[j++]); //error handling
		ft_free_2d((void **)temp);
		av++;
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
