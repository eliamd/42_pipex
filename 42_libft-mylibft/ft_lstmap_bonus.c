/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:33:24 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:13:23 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_lstmap applies 'f' to each element of 'lst' and creates a new list.
and creates a new list.
Takes 'lst' (linked list), 'f' (function to apply)
and 'del' (function to free contents).
Returns the new list, or NULL on failure.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp_next;

	newlist = NULL;
	while (lst)
	{
		temp_next = ft_lstnew(NULL);
		if (!temp_next)
		{
			ft_lstclear(&newlist, del);
			break ;
		}
		temp_next->content = f(lst->content);
		ft_lstadd_back(&newlist, temp_next);
		lst = lst->next;
	}
	return (newlist);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void delcontent(void *content)
// {
// 	free(content);
// }

// void	*transform(void *content)
// {
// 	char *new_content = ft_strdup("Mohahah 😈 ");

// 	if (content)
// 	{
// 		printf("str : %s\n", (const char *)content);
// 		printf("new cont : %s\n", (const char *)new_content);
// 		return (ft_strjoin((const char *)new_content, (const char *)content));
// 	}
// 	return (NULL);
// }

// int main(void)
// {
// 	t_list *node;
// 	char *content = ft_strdup("bonjour !");

// 	node = ft_lstnew(content);
// 	if (node)
// 	{
// 		t_list *newbuble1;
// 		char *newbuble1_content = ft_strdup("coucou !");

// 		newbuble1 = ft_lstnew(newbuble1_content);
// 		if (newbuble1)
// 		{
// 			ft_lstadd_back(&node, newbuble1);

// 			t_list *newbuble2;
// 			char *newbuble2_content = ft_strdup("salut !");
// 			newbuble2 = ft_lstnew(newbuble2_content);
// 			if (newbuble2)
// 			{
// 				ft_lstadd_back(&node, newbuble2);

// 				// Utiliser ft_lstmap pour transformer la liste
// 				t_list *mapped_list = ft_lstmap(node, transform, delcontent);
// 				if (mapped_list)
// 				{
// 					t_list *temp = mapped_list;
// 					while (temp)
// 					{
// 						printf("Mapped content: %s\n", (char *)temp->content);
// 						temp = temp->next;
// 					}
// 					ft_lstclear(&mapped_list, delcontent);
// 				}
// 				else
// 				{
// 					printf("Failed to map list\n");
// 				}
// 			}
// 			else
// 			{
// 				printf("Failed to create newbuble2\n");
// 			}
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

// 	return 0;
// }
