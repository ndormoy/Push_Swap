/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:43:59 by noedormoy         #+#    #+#             */
/*   Updated: 2021/12/28 10:36:12 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_all_sorted(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp_nxt;

	tmp = lst;
	tmp_nxt = tmp->next;
	while (tmp && tmp->next)
	{
		tmp_nxt = tmp->next;
		if (tmp->content > tmp_nxt->content)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_all_inv_sorted(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp_nxt;

	tmp = lst;
	tmp_nxt = tmp->next;
	while (tmp && tmp->next)
	{
		tmp_nxt = tmp->next;
		if (tmp->content < tmp_nxt->content)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
