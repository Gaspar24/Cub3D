/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:13:18 by pfalli            #+#    #+#             */
/*   Updated: 2024/05/08 15:53:40 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*fill_line_buffer(int fd, char *left_c, char *buffer);
char	*set_line(char *line);

char	*reset_left_c(char **left_c)
{
	free(*left_c);
	*left_c = NULL;
	return (NULL);
}

char	*get_next_line(int fd, int reset)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	if (reset)
		return (reset_left_c(&left_c));
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (0);
	}
	line = fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	left_c = set_line(line);
	return (line);
}

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	int		c_read;
	char	*temp;

	c_read = 1;
	while (c_read > 0)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == -1)
		{
			free(left_c);
			return (0);
		}
		if (c_read == 0)
			break ;
		buffer[c_read] = 0;
		if (!left_c)
			left_c = ft_strdup_gnl("");
		temp = left_c;
		left_c = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

// it returns the substring of chars left
char	*set_line(char *line)
{
	int		i;
	char	*left_c;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (0);
	left_c = ft_substr(line, i + 1, ft_strlen_gnl(line) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line[i + 1] = 0;
	return (left_c);
}

//---------------------------------------------------

//	int	main(void)
//	{
//		int fd;
//		char *str;
//		fd = open("line.txt", O_RDONLY);
//
//		while ((str = get_next_line(fd)))
//		{
//			printf("%s", str);
//			free(str);
//		}
//
//		close(fd);
//	}
//
//	char	*ft_strchr(const char *s, int c)
//	{
//		while (*s != '\0')
//		{
//			if (*s == (char)c)
//				return ((char *)s);
//			s++;
//		}
//		if (*s == (char)c)
//			return ((char *)s);
//		return (NULL);
//	}
//
//	// new strign in a new allocated string
//	char	*ft_strdup(char *s1)
//	{
//		char			*dest;
//		unsigned int	i;
//
//		dest = (char *) malloc(ft_strlen(s1) + 1);
//		if (!dest)
//			return (NULL);
//		i = 0;
//		while (s1[i])
//		{
//			dest[i] = s1[i];
//			i++;
//		}
//		dest[i] = 0;
//		return (dest);
//	}
//
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
//	// extract a substrign from another string
//	char	*ft_substr(char const *s, unsigned int start, size_t len)
//	{
//		char	*arr;
//		size_t	len_s;
//		size_t	i;
//
//		if (s == NULL)
//			return (NULL);
//		len_s = ft_strlen(s);
//		if (start > len_s)
//			return (ft_strdup(""));
//		if (start + len > len_s)
//			len = len_s - start;
//		arr = (char *)malloc(len + 1);
//		if (arr == NULL)
//			return (NULL);
//		i = 0;
//		while (i < len)
//		{
//			arr[i] = s[start + i];
//			i++;
//		}
//		arr[i] = 0;
//		return (arr);
//	}
//
//	// join 2 string inside a new string
//	char	*ft_strjoin(char const *s1, char const *s2)
//	{
//		char	*dest;
//		int		i, x;
//
//
//		i = 0;
//		x = 0;
//		dest = malloc(((int)ft_strlen(s1) + (int)ft_strlen(s2)) + 1);
//		if (dest == 0)
//			return (0);
//		while (s1[i])
//		{
//			dest[i] = s1[i];
//			i++;
//		}
//		while (s2[x])
//		{
//			dest[i] = s2[x];
//			x++;
//			i++;
//		}
//		dest[i] = 0;
//		return (dest);
//	}