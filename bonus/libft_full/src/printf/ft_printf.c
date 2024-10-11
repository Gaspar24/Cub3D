/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:29:40 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 13:48:31 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_element(char element, va_list ap)
{
	int	count;

	count = 0;
	if (element == 'c')
		count += ft_print_char(va_arg(ap, int));
	if (element == 's')
		count += ft_print_string(va_arg(ap, char *));
	if (element == 'd' || element == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	if (element == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long));
	if (element == 'u')
		count += ft_print_u(va_arg(ap, unsigned int));
	if (element == 'x')
		count += ft_print_hexa(va_arg(ap, unsigned int));
	if (element == 'X')
		count += ft_print_up_hexa(va_arg(ap, unsigned int));
	if (element == '%')
		count += ft_print_percentage();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += print_element(format[i + 1], ap);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

//	int main()
//	{
//		ft_print_char('0');
//		ft_print_char('x');
//		ft_print_char('0');
//		ft_print_char('0');
//		ft_print_char('0');
//		ft_print_char('0');
//		ft_print_char('0');
//	}