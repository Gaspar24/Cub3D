/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:48:06 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:43:43 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// locate a substring in a big string

// Remember, causing intentional segmentation faults is not good practice
// in actual programming.
// Always ensure that your code handles NULL pointers appropriately 
// to prevent segmentation faults and undefined behavior.

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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	x;

	x = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (*big != 0 && len >= little_len)
	{
		if (*big == *little)
		{
			while (little[x] != '\0' && big[x] == little[x])
			{
				x++;
			}
			if (x == little_len)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

//	// Test function for ft_strnstr
//	void test_ft_strnstr(const char *big, const char *little, size_t len) {
//		 char *result = ft_strnstr(big, little, len);
//		 if (result != NULL) {
//		     printf("'%s' found in '%s'\n", little, big);
//		 } else {
//		     printf("'%s' not found in '%s'\n", little, big);
//		 }
//	}
//
//	int main() {
//		 const char *str = "lorem ipsum dolor sit amet";
//		 const char *substring1 = "amet";
//		 const char *substring2 = "\0"; ///////
//		 const char *substring3 = "";
//
//		 printf("String: '%s'\n", str);
//
//		 test_ft_strnstr(str, substring1, 30);
//		 test_ft_strnstr(str, substring2, 30);
//		 test_ft_strnstr(str, substring3, 30);
//
//		 return (0);
//	}