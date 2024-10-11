/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:07 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:37:02 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	while (temp != 0)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

// int main() 
// {
//     t_list *head = malloc(sizeof(t_list));
//     t_list *second = malloc(sizeof(t_list));
//     t_list *third = malloc(sizeof(t_list));
// 
//     head->content = 1;
//     head->next = second;
// 
//     second->content = 2;
//     second->next = third;
// 
//     third->content = 3;
//     third->next = NULL;
// 
//     int size = ft_lstsize(head);
// 
//     printf("The size of the list is: %d\n", size);
// 
//     free(head);
//     free(second);
//     free(third);
// 
//     return 0;
// }