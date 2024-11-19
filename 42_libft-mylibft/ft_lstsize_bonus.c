/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:21:33 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:13:44 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_lstsize counts the number of elements in 'lst'.
Takes 'lst' (linked list).
Returns the number of elements in the list.
*/

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	while (lst)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// int main(void)
// {
// 	t_list *node;
// 	char *content = "Hello, world!";

// 	node = ft_lstnew(content);
// 	if (node)
// 	{
// 		printf("Node content: %s\n", (char *)node->content);
// 		printf("Node next: %p\n", (void *)node->next);

// 		t_list *newbuble1;
// 		char *newbuble1_content = "Coucou";

// 		// Allouer de la mémoire pour newbuble1
// 		newbuble1 = ft_lstnew(newbuble1_content);
// 		if (newbuble1)
// 		{
// 			ft_lstadd_front(&node, newbuble1);
// 			printf("Node content after add: %s\n", (char *)node->content);
// 			printf("Node next after add: %p\n", (void *)node->next);
// 			printf(">>>>> Taille : %i", ft_lstsize(newbuble1));
// 		}
// 		else
// 		{
// 			printf("Failed to create newbuble1\n");
// 		}
// 	}
// 	else
// 	{
// 		printf("Failed to create node\n");
// 	}

// 	// Libérer la mémoire allouée
// 	free(node);
// 	return 0;
// }
