/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:26:39 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:31:26 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi converts a string of char to int

// The atoi() function skips all the white space characters at the starting of
// the string. It also converts the characters as the number part and stops
// when it finds the first non-number character.

// int doesn't need end \0

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	res = 0;
	negative = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * negative);
}
//
//
// #include <stdio.h>
//
// int	main()
// {
// 	char str[] = "12345";
// 	int x;
//
// 	x = atoi(str);
//
// 	printf("this is the integer: %d\n", x);
//
// 	return (x);
// }