/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:01:09 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 11:03:26 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, count * size);
	return ((void *)tab);
}
