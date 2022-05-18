/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:16:45 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 19:16:56 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long long	ft_atoll(const char *str)
{
	unsigned long long	atoll;
	int					neg;

	neg = 1;
	atoll = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		atoll = atoll * 10 + *str - 48;
		str++;
	}
	return ((long long)atoll * neg);
}
