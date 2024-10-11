/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:43:58 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:41:45 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*dest;
	int		i;
	int		x;

	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	i = 0;
	x = 0;
	dest = malloc(total_len + 1);
	if (dest == 0)
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	while (x < (int)ft_strlen(s2))
	{
		dest[i] = s2[x];
		x++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

	// int main()
	// {
	// 	char a[]= "voglio";
	// 	char b[]= "mangiare";
	// 	char *c;
	//
	// 	c = ft_strjoin(a, b);
	//
	// 	printf("%s\n", c);
	// }