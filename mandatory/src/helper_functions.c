/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:50:28 by msacaliu          #+#    #+#             */
/*   Updated: 2024/10/09 12:21:13 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// bool	check_name_before_cub(char *str)
// {
	
// }


bool	check_map_format(char *str)
{
	int		length;
	char	*new_str;
	int		i;

	i = 0;
	if(!str || ft_strlen(str) < 5)
		return(printf("Error\n"),
			printf("Wrong file format\n"),true);
	if(str[ft_strlen(str) - 5] == '/') ///maybe something else later
		return(printf("Error\n"),
			printf("Wrong file format\n"),true);
	new_str = malloc(sizeof(char ) * ft_strlen(".cub") + 1);
	if(!new_str)
		return (free(new_str),printf("malloc\n"),true);
	length = ft_strlen(str) - 4;
	while(length < ft_strlen(str))
		new_str[i++] = str[length++];
	new_str[i] = '\0';
	if(!strcmp(new_str, ".cub"))
		return(free(new_str),false);
	else
		return(free(new_str),printf("Error\n"),
			printf("Wrong file format\n"),true);

}

void	count_commas(char *str)
{
	int	comma_count;

	comma_count = 0;
	while (*str)
	{
		if (*str == ',')
			comma_count++;
		str++;
	}
	if (comma_count != 2)
	{
		printf("❌ Error: Color format is invalid\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_color_string(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha((int)string[i]) != 0)
		{
			printf("❌ Error: Color string contains letters\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}


void	print_error(char *str)
{
	printf("❌ Error: %s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v');
}