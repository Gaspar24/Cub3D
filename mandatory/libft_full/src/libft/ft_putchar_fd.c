/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:20:50 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:39:12 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function that writes a single character to a specified file descriptor

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//	int main() {
//			char character = 'A'; // Character to write
//			FILE *file;
//
//
// Redirect stdout to a file ("output.txt" will be created or overwritten)
//			file = freopen("output.txt", "w", stdout);
//			if (file == NULL) {
//			  perror("Error opening the file");
//			  return (1);
//			}
//
//
// Write the character using ft_putchar_fd which will write to the 
// redirected stdout
//			ft_putchar_fd(character, STDOUT_FILENO);
//
//			// Close the file
//			fclose(file);
//
//			printf("Character '%c' written to the file.\n", character);
//
//			return (0);
//	}