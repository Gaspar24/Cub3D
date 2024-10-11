/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:19:08 by pfalli            #+#    #+#             */
/*   Updated: 2024/05/21 14:06:25 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

//	locate the first occurence c in the string,
//	in this case a check for '\n' inside the buffer!!!!
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

// new strign in a new allocated string
char	*ft_strdup_gnl(const char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *)malloc(ft_strlen_gnl(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen_gnl(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

// extract a substrign from another string
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	len_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen_gnl(s);
	if (start > len_s)
		return (ft_strdup_gnl(""));
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

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		x;

	i = 0;
	x = 0;
	dest = (char *)malloc(((int)ft_strlen_gnl(s1) + (int)ft_strlen_gnl(s2))
			+ 1);
	if (dest == 0)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		dest[i] = s2[x];
		x++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
