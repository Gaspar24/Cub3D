/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:48:20 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:44:18 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// the function check if the are the chars of "set" in 
// the beginning or end of the
// string and create a new string without them

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
//
static int	findset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && findset(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (end > start && findset(s1[end - 1], set))
		end--;
	arr = (char *)malloc((end - start + 1));
	if (!arr)
		return (NULL);
	while (start < end)
		arr[i++] = s1[start++];
	arr[i] = 0;
	return (arr);
}

//	int	main(void)
//	{
//		char *a = "$^&";
//		char *set = "$^&";
//		ft_strtrim(a, set);
//
//		printf("%s\n", a);
//	}