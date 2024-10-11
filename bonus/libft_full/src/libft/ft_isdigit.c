/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:18:20 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/14 11:33:45 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//
//	int	main(void)
//	{
//		char	x;
//
//		x = '9';
//		ft_isdigit(x);
//		printf("it's alphabet or not %c", x);
//		return (0);
//	}
//