/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:36:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/08 13:36:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup_printf(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen_printf(s) + 1);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
