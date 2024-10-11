/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:14:56 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:40:39 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the function split the array of words putting in the middle (char c)

#include "libft.h"

static char	**pr_word(char **split, const char *start, char const *s, int i)
{
	int	j;

	j = 0;
	while (start < s)
	{
		split[i][j] = *start;
		j++;
		start++;
	}
	split[i][j] = 0;
	return (split);
}

static int	countwords(char const *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*s)
	{
		if (*s != c && x == 0)
		{
			count++;
			x = 1;
		}
		else if (*s == c)
			x = 0;
		s++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	const char	*start;
	char		**split;

	i = 0;
	split = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (split == NULL || s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = (char *)malloc(((s - start) + 1) * sizeof(char));
			if (split[i] == NULL)
				return (ft_free(split, i));
			pr_word(split, start, s, i);
			i++;
		}
		else
			s++;
	}
	return (split[i] = NULL, split);
}

// int	main(void)
// {
// 	int i = 0;
// 	char const *input = "Hello, supp ahahah";
// 	char **result = ft_split(input, ' ');

// 	if (result)
// 	{
// 		while (result[i] != NULL)
// 		{
// 			printf("%s$$$", result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Splitting failed.\n");
// 	}
// 	return (0);
// }