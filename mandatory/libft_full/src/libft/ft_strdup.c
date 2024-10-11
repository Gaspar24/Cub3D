/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:40 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:41:14 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strdup() function allocates sufficient memory for a 
// copy of the string s1,does the copy, and returns a pointer to it.

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len_s1;

	len_s1 = ft_strlen(s1) + 1;
	arr = malloc(len_s1);
	if (arr == NULL)
		return (NULL);
	ft_memcpy(arr, s1, len_s1);
	return (arr);
}

//	int main()
//	{
//		char a[]= "tu vuoi fare l'americano";
//
//		ft_strdup(a);
//
//		printf("result: %s\n", a);
//
//	}
//