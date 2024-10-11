/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:53:34 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 13:32:07 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	int		*arr;
	size_t	i;

	total_size = count * size;
	i = 0;
	arr = (int *)malloc(total_size);
	if (arr == 0)
	{
		return (0);
	}
	while (i < total_size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
