/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:29:54 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:37:45 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* it compares the two strings */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, int n)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	i = 0;
	while (n > i)
	{
		if ((unsigned char)ptr1[i] != (unsigned char)ptr2[i])
		{
			return ((int)(ptr1[i] - ptr2[i]));
		}
		i++;
	}
	return (0);
}

//	int	main(void)
//	{
//		const char	*str1 = "testss";
//		const char	*str2 = "test";
//		int	ret;
//	
//		ret = ft_memcmp(str1, str2, 5);
//		if (ret > 0)
//		{
//			printf("str1 is bigger than str2");
//		}
//		else if (ret < 0)
//		{
//			printf("str1 is less than str2");
//		}
//		else
//		{
//			printf("strings are the same");
//		}
//		return (0);
//	}
//	