/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:10:53 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:37:25 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* it copy one letter to a chosen byte of dest string */

#include "libft.h"

void	*ft_memchr(const void *memory, int print, size_t n)
{
	size_t			x;
	unsigned char	*ptr;
	unsigned char	pls;

	x = 0;
	ptr = (unsigned char *)memory;
	pls = (unsigned char)print;
	while (x < n)
	{
		if (ptr[x] == pls)
		{
			return (ptr + x);
		}
		x++;
	}
	return (NULL);
}

//	int main()
//	{
//		char * str;
//
//		str = ft_memchr("bonjour", 'r', 3);
//
//		printf("result: %s\n", str);
//	}