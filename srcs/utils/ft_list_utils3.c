/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:44:09 by noedormoy         #+#    #+#             */
/*   Updated: 2021/12/28 10:42:32 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_scan_top_to_bot(t_list *lst, int median, int size, int direction)
{
	t_list	*tmp;
	int		pos;
	int		i;

	tmp = lst;
	pos = 0;
	i = 0;
	while (tmp && i < size)
	{
		if (tmp->content < median && direction == 1)
			return (pos);
		if (tmp->content > median && direction == 2)
			return (pos);
		tmp = tmp->next;
		pos++;
		i++;
	}
	return (-1);
}

int	ft_scan_bot_to_top(t_list *lst, int median, int size, int direction)
{
	int		pos;
	int		real_pos;
	int		i;
	t_list	*tmp;

	tmp = lst;
	pos = 0;
	real_pos = -1;
	i = 0;
	while (tmp && i < size)
	{
		if (lst->content < median && direction == 1)
			real_pos = pos;
		if (lst->content > median && direction == 2)
			real_pos = pos;
		pos++;
		i++;
	}
	return (real_pos);
}
