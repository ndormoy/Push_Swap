/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:41:06 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 10:51:51 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else if (!new)
		return ;
	else
	{
		new ->next = *alst;
		*alst = new;
	}
}

int	ft_bigger(t_list *lst)
{
	int		bigger;
	t_list	*tmp;

	tmp = lst;
	bigger = tmp->content;
	while (tmp)
	{
		if (bigger < tmp->content)
			bigger = tmp->content;
		tmp = tmp->next;
	}
	free(tmp);
	return (bigger);
}

int	ft_smaller(t_list *lst)
{
	int		smaller;
	t_list	*tmp;

	tmp = lst;
	smaller = tmp->content;
	while (tmp)
	{
		if (smaller > tmp->content)
			smaller = tmp->content;
		tmp = tmp->next;
	}
	free(tmp);
	return (smaller);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*previous;
	t_list	*current;

	if (lst && *lst && del)
	{
		current = *lst;
		while (current)
		{
			previous = current;
			current = current->next;
			free(previous);
		}
		*lst = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)((void *)&(lst)->content);
	free(lst);
}
