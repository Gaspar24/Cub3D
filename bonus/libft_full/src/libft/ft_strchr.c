/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:13:10 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 13:32:47 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strchr() function checks whether the original
// string contains defined characters.
// If the character is found inside the string,
// it returns a pointer value; otherwise,
// it returns a null pointer. While using the strchr()
// function in the C programming language,
// we need to import the <string.h>

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
