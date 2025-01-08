/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:44:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/08 18:24:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!str[i])
			return (0);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res * sign < (long)INT_MIN || res * sign > (long) INT_MAX)
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}
