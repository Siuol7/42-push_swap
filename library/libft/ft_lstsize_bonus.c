/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:08:40 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:01 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
// #include <stdio.h>

// int	main()
// {
// 	char	x[5] = "abcd";
// 	char	y[6] = "abcde";
// 	t_list *top = NULL;
// 	t_list *node1 = ft_lstnew((void *)x);
// 	t_list	*node2 = ft_lstnew((void *)y);

// 	ft_lstadd_front(&top, node1);
// 	ft_lstadd_front(&top,node2);
// 	printf("%d\n", ft_lstsize(top));
// 	return(0);
// }