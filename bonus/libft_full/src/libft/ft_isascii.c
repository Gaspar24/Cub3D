/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:03 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:33:22 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//	int	main(void)
//	{
//		char	x;
//
//		printf("give me a digit:");
//		scanf("%c", &x);
//		ft_isascii(x);
//		printf("the digit is part of ASCII");
//		return (0);
//	}
//