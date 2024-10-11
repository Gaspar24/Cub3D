/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:21:30 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 14:33:36 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long num)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		ft_print_hexa(num / 16);
		ft_print_hexa(num % 16);
	}
	else if (num < 10)
		ft_print_char(num + 48);
	else
		ft_print_char(num + 87);
	len = get_len(num);
	return (len);
}

//	int	ft_print_hexa(unsigned long long num, const char format)
//	{
//		if (num >= 16)
//		{
//			ft_print_hexa(num / 16, format);
//			ft_print_hexa(num % 16,format);
//		}
//		else
//		{
//			if (num < 10)
//				ft_print_char(num + 48);
//			else
//			{
//				if (num == 'x')
//					ft_print_char(num + 55);
//				else if (num == 'X')
//					ft_print_char(num + 87);
//			}
//		}
//		return (get_len(num));
//	}
