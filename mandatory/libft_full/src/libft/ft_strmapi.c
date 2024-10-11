/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:33:14 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:43:10 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	int	ft_strlen(const char *str)
//	{
//		int	x;
//
//		x = 0;
//		while (str[x] != '\0')
//		{
//			x++;
//		}
//		return (x);
//	}
//
//	char increment(unsigned int index, char c)
//	{
//			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
//		     return (c + 1);
//		 }
//		 return (c);
//	}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*ptr;

	i = 0;
	length = ft_strlen(s);
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	while (length > i)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

//	int main()
//	{
//		char *arr = "hola";
//
//
//		char *str = ft_strmapi(arr, increment);
//		printf( "%s", str);
//		return (0);
//	}