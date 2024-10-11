/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:17:21 by pfalli            #+#    #+#             */
/*   Updated: 2024/01/16 15:17:02 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
		count += ft_print_char(nbr + '0');
	else
	{
		count += ft_print_u(nbr / 10);
		count += ft_print_u(nbr % 10);
	}
	return (count);
}
