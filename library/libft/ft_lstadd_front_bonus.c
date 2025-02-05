/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:56:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// #include <stdio.h>

// void	ft_printlst(t_list **top)
// {
// 	t_list	*temp;

// 	temp = *top;
// 	if (!*top)
// 		return ;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }

// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[6] = "abcde";
// 	t_list *top = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&top, node1);
// 	ft_lstadd_front(&top,node2);
// 	ft_printlst(&top);
// 	return(0);
// }