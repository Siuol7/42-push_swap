/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:54:35 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 07:39:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void 	parse_ops(t_pushswap*ps, char *ops)
{
	if (ops == "ra")
		ra_bn(ps);
	else if (ops == "rb")
		rb_bn(ps);
	else if (ops == "rr")
		rr_bn(ps);
	else if (ops == "rra")
		rra_bn(ps);
	else if (ops == "rrb")
		rrb_bn(ps);
	else if (ops == "rrr")
		rrr_bn(ps);
	else if (ops == "sa")
		sa_bn(ps);
	else if (ops == "sb")
		sb_bn(ps);
	else if (ops == "ss")
		ss_bn(ps);
	else if (ops == "pa")
		pa_bn(ps);
	else if (ops == "pb")
		pb_bn(ps);
	else
		return ;
}

static get_ops(char *ops)
{
	
}

void	read_and_exec(t_pushswap *ps)
{
	int		readbytes;
	char	line[5];

	while (1)
	{
		readbytes = read(0, line, 4);
		if (readbytes < 0 || line[readbytes - 1] != '\n')
		{
			ft_printf_fd(2, "Error\n");
			return ;
		}
		else if (readbytes == 0)
			return ;
		parse_ops(ps, get_ops(line));
	}
}