/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:01:22 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:12:21 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_lstclear deletes and frees all elements of 'lst'.
Takes 'lst' (address of pointer to start of list)
and 'del' (function to delete contents).
Returns nothing.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// void	delcontent(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// int main(void)
// {
// 	t_list *node;
// 	char *content = ft_strdup("bonjour !");

// 	node = ft_lstnew(content);
// 	if (node)
// 	{
// 		printf("Node content: %s\n", (char *)node->content);
// 		printf("Node next bf add: %p\n", (void *)node->next);

// 		t_list *newbuble1;
// 		char *newbuble1_content = ft_strdup("coucou !");

// 		// Allouer de la mémoire pour newbuble1
// 		newbuble1 = ft_lstnew(newbuble1_content);
// 		if (newbuble1)
// 		{
// 			ft_lstadd_back(&node, newbuble1);
// 			printf(">> next cont aft add: %s\n", (char *)node->next->content);
// 			printf(">> next after add: %p\n", (void *)node->next);
// 			printf(">>>>> Taille : %i\n", ft_lstsize(node));
// 			printf(">>>>> Last : %s\n", (char *)ft_lstlast(node)->content);

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
// 	if (node)
// 		ft_lstclear(&node, delcontent);

// 	printf(">>>>> Taille apres : %i\n", ft_lstsize(node));
// 	return 0;
// }
