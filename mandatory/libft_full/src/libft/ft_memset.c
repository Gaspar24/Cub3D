/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:46:47 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:38:48 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Refill the string with an int for tot size

// Casting to unsigned char * can be useful in scenarios where you want to 
// interpret the data pointed to by memory as a sequence of bytes 
// This casting operation allows the program to access the memory byte by byte, 
// treating each byte as an unsigned character.

#include "libft.h"

void	*ft_memset(void *memory, int c, int len)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)memory;
	while (i < len)
	{
		ptr[i++] = (unsigned char)c;
	}
	return (memory);
}

//
//#include <stdio.h>
//
// int	main(void)
//{
//	char memory[] = "Paperone";
//
//	ft_memset(memory, '$', 5);
//
//	printf("Refilled string: %s\n", memory);
//
//	return (0);
//}