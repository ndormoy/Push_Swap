/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimise2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:51:24 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/29 12:54:48 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_comb2(t_list **lst)
{
	int		nb2;
	int		nb3;
	int		nb4;

	nb2 = (*lst)->next->content;
	nb3 = (*lst)->next->next->content;
	nb4 = (*lst)->next->next->next->content;
	if (nb2 == 2 && nb3 == 4 && nb4 == 3)
		return (0);
	else if (nb2 == 6 && nb3 == 8 && nb4 == 7)
		return (1);
	return (-1);
}

int	ft_something_to_delete2(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next && tmp->next->next && tmp->next->next->next)
	{
		if (ft_is_comb2(&tmp) >= 0)
		{
			tmp = *lst;
			return (0);
		}
		tmp = tmp->next;
	}
	tmp = *lst;
	return (-1);
}

void	ft_transform_comb2(t_list **lst)
{
	t_list	*save_next;
	t_list	*new;
	t_list	*new2;
	t_list	*to_del;

	to_del = (*lst)->next;
	if ((*lst)->next->next->next->next)
		save_next = (*lst)->next->next->next->next;
	else
		save_next = NULL;
	if (ft_is_comb2(lst) == 0)
	{
		new = ft_lstnew(1);
		new2 = ft_lstnew(4);
	}
	else
	{
		new = ft_lstnew(5);
		new2 = ft_lstnew(8);
	}
	(*lst)->next = new;
	new->next = new2;
	new2->next = save_next;
	to_del->next->next->next = NULL;
	ft_lstclear(&to_del, free);
}

int	ft_optimise_2(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (ft_something_to_delete2(lst) == 0)
	{
		tmp = *lst;
		while (tmp && tmp->next && tmp->next->next && tmp->next->next->next)
		{
			if (ft_is_comb2(&tmp) >= 0)
				ft_transform_comb2(&tmp);
			tmp = tmp->next;
		}
	}
	tmp = *lst;
	return (0);
}
