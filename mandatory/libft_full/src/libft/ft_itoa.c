/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:22:18 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:34:53 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert a int to a string of char

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_get_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_get_int_len(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

//	int	main()
//	{
//		int		n;
//		char	*res;
//	
//		n = -2147483648LL;
//	
//		res = ft_itoa(n);
//		if (res != NULL)
//		{
//			printf("%s\n", res);
//			free(res);
//		}
//		else
//		{
//			printf("Memory allocation failed.\n");
//		}
//		return (0);
//	}
//	