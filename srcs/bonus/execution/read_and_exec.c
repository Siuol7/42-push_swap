/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:54:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 09:55:42 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void 	parse_ops(t_pushswap*ps, char *ops)
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
		return ;
}

static char *get_ops(t_pushswap *ps, char *line)
{
	int		length;
	char	*ops;

	length = ft_strlen(line);
	ops = malloc(length);
	if (!ops)
		return (NULL);
	ft_memcpy(ops, line, length - 1);
	ops[length - 1] = '\0';
	parse_ops(ps, ops);
	free(ops);
	return (ops);
}

int	read_and_exec(t_pushswap *ps)
{
	int		readbytes;
	char	line[5];

	while (1)
	{
		readbytes = read(0, line, 4);
		if (readbytes < 0)
		{
			ft_printf_fd(2, "Error\n");
			return (0);
		}
		else if (readbytes == 0 && line[0] == '\0')
			return (1);
		line[readbytes] = '\0';
		if ((line[readbytes - 1] != '\n') || !get_ops(ps, line))
		{
			ft_printf_fd(2, "Error\n");
			return (0);
		}
	}
}
