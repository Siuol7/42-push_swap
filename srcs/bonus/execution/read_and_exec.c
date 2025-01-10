/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:54:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 09:57:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int 	parse_ops(t_pushswap*ps, char *ops)
{
	if (ft_strcmp(ops,"ra") == 0)
		ra_bn(ps);
	else if (ft_strcmp(ops, "rb") == 0)
		rb_bn(ps);
	else if (ft_strcmp(ops, "rr") == 0)
		rr_bn(ps);
	else if (ft_strcmp(ops, "rra") == 0)
		rra_bn(ps);
	else if (ft_strcmp(ops, "rrb") == 0)
		rrb_bn(ps);
	else if (ft_strcmp(ops, "rrr") == 0)
		rrr_bn(ps);
	else if (ft_strcmp(ops, "sa") == 0)
		sa_bn(ps);
	else if (ft_strcmp(ops, "sb") == 0)
		sb_bn(ps);
	else if (ft_strcmp(ops, "ss") == 0)
		ss_bn(ps);
	else if (ft_strcmp(ops, "pa") == 0)
		pa_bn(ps);
	else if (ft_strcmp(ops, "pb") == 0)
		pb_bn(ps);
	else
		return (0);
	return (1);
}

static char	*get_ops(int i)
{
	int		readbytes;
	char	word;
	char	*line;

	line = malloc(5);
	if (!line)
		return (NULL);
	while (1)
	{
		readbytes = read(0, &word, 1);
		if (readbytes < 0)
			return (NULL);
		if (readbytes == 0 && i == 0)
			break ;
		if (word == '\n')
			break;
		line[i++] = word;
		if (i == 4 && line[3] != '\n')
			return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int read_and_exec(t_pushswap *ps, int *status)
{
	char	*ops;

	while (1)
	{
		ops = get_ops(0);
		if (ops[0] == '\0')
			break;
		else if (!ops)
		{
			ft_printf_fd(2, "Error\n");
			return (0);
		}
		if (!parse_ops(ps, ops))
		{
			ft_printf_fd(2, "Error\n");
			free(ops);
			return (0);
		}
		free(ops);
	}
	ft_issorted(ps, status);
	return (1);
}
