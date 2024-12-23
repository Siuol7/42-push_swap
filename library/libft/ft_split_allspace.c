/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_allspace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:45:47 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/22 15:37:07 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
			cnt++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (cnt);
}

static	size_t	ft_wordlength(char const *start)
{
	size_t	wlen;

	wlen = 0;
	while (start[wlen] && !ft_isspace(start[wlen]))
		wlen++;
	return (wlen);
}

static void	ft_free(char **final, size_t cur)
{
	while (cur-- > 0)
	{
		free(final[cur]);
		final[cur] = NULL;
	}
	free(final);
	final = NULL;
}

static char	**ft_splitting(char **final, char const *s)
{
	size_t	i;
	size_t	j;
	size_t	wlen;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && ft_isspace(s[j]))
			j++;
		if (s[j] && !ft_isspace(s[j]))
		{
			wlen = ft_wordlength(&s[j]);
			final[i] = ft_substr(s, j, wlen);
			if (!final[i])
			{
				ft_free(final, i);
				return (NULL);
			}
			i++;
			j += wlen;
		}
	}
	final[i] = NULL;
	return (final);
}

char	**ft_split_allspace(char const *s)
{
	char	**final;
	size_t	totlen;

	if (!s)
		return (NULL);
	totlen = ft_wordcount(s);
	final = (char **)malloc((totlen + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	return (ft_splitting(final, s));
}
