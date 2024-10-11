/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:18:43 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:44:36 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the fucntion extrapolate a substring from the string with a 
// given start and len

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	len_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (start + len > len_s)
		len = len_s - start;
	arr = (char *)malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

//	int main() {
//		 char a[] = "tu vuoi fare l'americano";
//		 char *sub = ft_substr(a, 3, 9);
//
//		 if (sub != NULL) {
//		     printf("%s\n", sub);
//		     free(sub);
//		 } else {
//		     printf("Substring creation failed.\n");
//		 }
//
//		 return (0);
//	}
//