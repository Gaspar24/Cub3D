/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:12 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 14:47:03 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len(unsigned long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

int	ft_print_ptr(unsigned long num)
{
	int	len;

	if (num == 0)
		return (ft_print_string("(nil)"));
	else
	{
		len = 0;
		len += ft_print_string("0x");
		ft_print_hexa(num);
		len += get_len(num);
		return (len);
	}
}

//	int	ft_print_hexa(unsigned long num)
//	{
//		int	len;
//	
//		len = 0;
//		if (num >= 16)
//		{
//			ft_print_hexa(num / 16);
//			ft_print_hexa(num % 16);
//		}
//		else if (num < 10)
//			ft_print_char(num + 48);
//		else
//			ft_print_char(num + 87);
//		len = get_len(num);
//		return (len);
//	}
//	
//	
//	int	ft_print_char(char c)
//	{
//		write(1, &c, 1);
//		return (1);
//	}
//	
//	int	ft_print_string(char *string)
//	{
//		int	count;
//	
//		count = 0;
//		if (!string)
//			return (-1);
//		while (string[count])
//		{
//			write(1, &string[count], 1);
//			count++;
//		}
//		return (count);
//	}
//	
//	int main(void)
//	{
//		char *x = "pierotti";
//		int ptr = &x;
//	
//	
//		ft_print_ptr((unsigned long long)ptr);
//		return (0);
//	}