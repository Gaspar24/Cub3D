/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:57:51 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/03 16:59:49 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new_string;
	int		suf;

	i = 0;
	new_string = (char *)malloc((strlen(s1) + strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	suf = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[suf] = s2[i];
		i++;
		suf++;
	}
	new_string[suf] = '\0';
	return (new_string);
}
