/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:47:56 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/29 05:56:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strichr(const char *s, int c)
{
	char	val;
	size_t	i;

	i = 0;
	val = (char)c;
	while (s[i])
	{
		if (s[i] == val)
			return (i);
		i++;
	}
	if (s[i] == val)
		return (i);
	return (-1);
}