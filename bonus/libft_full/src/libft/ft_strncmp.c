/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:57:38 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:43:26 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strcmp() and strncmp() functions lexicographically compare the
// null-terminatedstrings s1 and s2.
// The strncmp() function compares not more than n characters.
// Because strncmp() is designed for comparing strings rather than binary
// data, characters that appear after a `\0' character are not compared.
// The strcmp() and strncmp() functions return an integer greater than,
// equal to,or less than 0, according as the string s1 is greater
// than, equal to, or less than the string s2.

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		while ((s1[i] || s2[i]))
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
	}
	else
	{
		while (n > i && (s1[i] || s2[i]))
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
	}
	return (0);
}

//	#include <stdio.h>
//	int	main(void)
//	{
//		char *str1 = "test\200";
//		char *str2 = "test\0";
//		int result;
//		result = ft_strncmp(str1, str2, -1);
//		if (result == 0)
//		{
//			printf("The characters of str1 and str2 are equal.\n");
//		}
//		else if (result < 0)
//		{
//			printf("The characters of str1 are less than str2.\n");
//		}
//		else
//		{
//			printf("The characters of str1 are greater than str2.\n");
//		}
//		return (0);
//	}