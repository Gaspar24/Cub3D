/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:28:21 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:38:25 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memmove() function copies len bytes from string src to string dst.
// The two strings may overlap; the copy is always done in
// a non-destructive manner.

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_src;
	char	*c_dst;

	if (!dst && !src)
		return (0);
	c_src = (char *)src;
	c_dst = (char *)dst;
	if (c_dst > c_src)
	{
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	}
	else
	{
		while (0 < len)
		{
			*c_dst++ = *c_src++;
			len--;
		}
	}
	return (dst);
}

//	int	main(void)
//	{
//		char memory[] = "Paperone";
//		char memory2[] = "dhcdhd";
//		char memory3[] = {65, 66, 67, 68, 69, 0, 45};
//		char memory4[] = { 0,  0,  0,  0,  0,  0, 0};
//
//		ft_memmove(memory4, memory3 , 7);
//
//		printf("Refilled string: %s\n", memory4);
//
//		return (0);
//	}