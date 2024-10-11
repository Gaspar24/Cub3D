/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:33:44 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/03 12:38:59 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_null_and_return(void *ptr)
{
	if (ptr == NULL)
	{
		return (-1);
	}
	return (0);
}

// void	free_map_copy(char **map_copy, int height)
// {
// 	int	i;

// 	i = 0;
// 	while (i < height)
// 	{
// 		free(map_copy[i]);
// 		i++;
// 	}
// 	free(map_copy);
// }

int	ft_strspn(const char *str, const char *accept)
{
	int			count;
	const char	*a;

	count = 0;
	while (str[count])
	{
		a = accept;
		while (*a)
		{
			if (str[count] == *a)
				break ;
			a++;
		}
		if (*a == '\0')
			break ;
		count++;
	}
	return (count);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*current;
	char		*token_start;

	if (str != NULL)
		current = str;
	if (current == NULL)
		return (NULL);
	while (*current && ft_strrchr(delim, *current))
		current++;
	if (*current == '\0')
		return (NULL);
	token_start = current;
	while (*current && !ft_strrchr(delim, *current))
		current++;
	if (*current)
	{
		*current = '\0';
		current++;
	}
	else
		current = NULL;
	return (token_start);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		count;
	const char	*r;

	count = 0;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
			{
				return (count);
			}
			r++;
		}
		s++;
		count++;
	}
	return (count);
}


