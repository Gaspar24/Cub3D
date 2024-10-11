/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uphexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:21:30 by pfalli            #+#    #+#             */
/*   Updated: 2024/01/22 15:27:33 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	get_len(unsigned long num)
// {
// 	int	count;

// 	count = 0;
// 	while (num != 0)
// 	{
// 		count++;
// 		count = count / 16;
// 	}
// 	return (count);
// }

int	ft_print_up_hexa(unsigned long num)
{
	if (num >= 16)
	{
		ft_print_up_hexa(num / 16);
		ft_print_up_hexa(num % 16);
	}
	else if (num < 10)
		ft_print_char(num + 48);
	else
		ft_print_char(num + 55);
	return (get_len(num));
}

//  int main()
//  {
//      unsigned long long number = 0xABCD12345678;
//
//      ft_print_hexa(number);
//
//      return (0);
//  }
