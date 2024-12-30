/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:03:10 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include <stdio.h>

// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[8] = "abcde  ";
// 	t_list *top = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&top, node1);
// 	ft_lstadd_front(&top,node2);
// 	ft_lstiter(top, (void *)printf);
// 	return(0);
// }