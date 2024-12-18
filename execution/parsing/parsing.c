/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/18 07:34:52 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

char	**parsing(char **av)
{
	char	**input;
	char	**final;

	while (++av)
	{
		input = ft_space_splitting(av);
		if(!input)
			error_parsing(input, final);
		final = ft_2djoin(final, input);
		if(!final)
			error_parsing(input, final);
		
}
