/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:54:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 11:50:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	parse_ops(t_pushswap*ps, char *ops)
{
	if (ft_strcmp(ops, "ra") == 0)
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

static void	ft_flush(char *line)
{
	char	word;

	read(0, &word, 1);
	while (word != '\n')
		read(0, &word, 1);
	free(line);
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
		if ((i == 0 && word == '\n') || (i == 3 && word != '\n'))
		{
			ft_flush(line);
			return (NULL);
		}
		if (word == '\n')
			break ;
		line[i++] = word;
	}
	line[i] = '\0';
	return (line);
}

int	read_and_exec(t_pushswap *ps)
{
	char	*ops;

	while (1)
	{
		ops = get_ops(0);
		if (!ops)
			return (0);
		else if (ops[0] == '\0')
			break ;
		if (!parse_ops(ps, ops))
		{
			free(ops);
			return (0);
		}
		free(ops);
	}
	return (1);
}
