/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:26:35 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:44:02 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// localize a char in the string and the last occurrance of c

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	a;

	a = c;
	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	while (len >= 0)
	{
		if (str[len] == a)
		{
			return ((char *)&str[len]);
		}
		len--;
	}
	return (0);
}

//	int	main(void)
//	{
//		const char *str = "tripouille!";
//		int targetChar1 = 'o';
//		int targetChar2 = 't';
//
//		// Test case 1: character found
//		char *result1 = ft_strrchr(str, targetChar1);
//		if (result1 != NULL)
//		{
//			printf("Character '%c' found XD\n", targetChar1);
//		}
//		else
//		{
//			printf("Character '%c' not found in the string :(\n", targetChar1);
//		}
//
//		// Test 2:
//		char *result2 = ft_strrchr(str, targetChar2 + 250);
//		if (result2 != NULL)
//		{
//			printf("Character '%c' found XD\n", targetChar2);
//		}
//		else
//		{
//			printf("Character '%c' not found in the string :(\n", targetChar2);
//		}
//	}