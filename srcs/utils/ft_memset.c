/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:02:36 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 11:16:07 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned int	i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
