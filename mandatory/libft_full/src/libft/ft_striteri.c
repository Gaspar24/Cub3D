/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:20:09 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 13:32:52 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// modifies the string s char by char directly inside the function (*f)

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s);
	while (length > i)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
