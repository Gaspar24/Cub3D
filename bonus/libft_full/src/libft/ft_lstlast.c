/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:26:40 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:36:04 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

//	int main() {
//	    // Linked list
//	    t_list *head = malloc(sizeof(t_list));
//	    t_list *second = malloc(sizeof(t_list));
//	    t_list *third = malloc(sizeof(t_list));
//	
//	    head->content = 1;
//	    head->next = second;
//	
//	    second->content = 2;
//	    second->next = third;
//	
//	    third->content = 3;
//	    third->next = NULL; 
//	
//	    t_list *last = ft_lstlast(head);
//	
//
//	    if (last != NULL) {
//	        printf("The data of the last element is: %d\n", last->data);
//	    } else {
//	        printf("The list is empty!\n");
//	    }
//
//	    free(head);
//	    free(second);
//	    free(third);
//	
//	    return 0;
//	}