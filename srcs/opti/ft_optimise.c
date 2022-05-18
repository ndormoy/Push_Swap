/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:38:50 by noedormoy         #+#    #+#             */
/*   Updated: 2021/12/29 12:19:14 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_comb(t_list **lst)
{
	int		nb2;
	int		nb3;

	nb2 = (*lst)->next->content;
	nb3 = (*lst)->next->next->content;
	if ((nb2 == 4 && nb3 == 8) || (nb2 == 8 && nb3 == 4))
		return (0);
	else if ((nb2 == 2 && nb3 == 3) || (nb2 == 3 && nb3 == 2))
		return (0);
	else if ((nb2 == 6 && nb3 == 7) || (nb2 == 7 && nb3 == 6))
		return (0);
	else if ((nb2 == 1 && nb3 == 1) || (nb2 == 5 && nb3 == 5))
		return (0);
	else if (nb2 == 9 && nb3 == 9)
		return (0);
	else if ((nb2 == 10 && nb3 == 11) || (nb2 == 11 && nb3 == 10))
		return (0);
	else if ((nb2 == 1 && nb3 == 5) || (nb2 == 5 && nb3 == 1))
		return (1);
	else if ((nb2 == 2 && nb3 == 6) || (nb2 == 6 && nb3 == 2))
		return (2);
	else if ((nb2 == 3 && nb3 == 7) || (nb2 == 7 && nb3 == 3))
		return (3);
	return (-1);
}

int	ft_something_to_delete(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next && tmp->next->next)
	{
		if (ft_is_comb(&tmp) >= 0)
		{
			tmp = *lst;
			return (0);
		}
		tmp = tmp->next;
	}
	tmp = *lst;
	return (-1);
}

void	ft_delete_comb(t_list **lst)
{
	t_list	*tmp;
	t_list	*to_del;

	tmp = *lst;
	to_del = tmp->next;
	tmp->next = tmp->next->next->next;
	to_del->next->next = NULL;
	ft_lstclear(&to_del, free);
}

void	ft_transform_comb(t_list **lst)
{
	t_list	*tmp;
	t_list	*save_next;
	t_list	*new;
	t_list	*to_del;

	tmp = *lst;
	to_del = tmp->next;
	if (tmp->next->next->next)
		save_next = tmp->next->next->next;
	else
		save_next = NULL;
	if (ft_is_comb(lst) == 1)
		new = ft_lstnew(9);
	else if (ft_is_comb(lst) == 2)
		new = ft_lstnew(10);
	else
		new = ft_lstnew(11);
	tmp->next = new;
	new->next = save_next;
	to_del->next->next = NULL;
	ft_lstclear(&to_del, free);
}

int	ft_optimise(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (ft_something_to_delete(lst) == 0)
	{
		tmp = *lst;
		while (tmp && tmp->next && tmp->next->next)
		{
			if (ft_is_comb(&tmp) == 0)
				ft_delete_comb(&tmp);
			else if (ft_is_comb(&tmp) >= 1)
				ft_transform_comb(&tmp);
			tmp = tmp->next;
		}
	}
	tmp = *lst;
	return (0);
}
