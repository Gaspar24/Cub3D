/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:30:15 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 13:49:17 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../inc/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_len(unsigned long num);
int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_string(char *string);
int		ft_print_nbr(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_percentage(void);
int		ft_print_ptr(unsigned long num);
int		ft_print_hexa(unsigned long num);
int		ft_print_up_hexa(unsigned long num);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif