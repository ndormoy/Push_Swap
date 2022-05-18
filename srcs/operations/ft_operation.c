/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:40:29 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/03 11:56:26 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sa(t_stack **stack)
{
	int		tmp;

	if (!(*stack)->a || !(*stack)->a->next)
		return ;
	if ((*stack)->a->next)
	{
		tmp = (*stack)->a->content;
		(*stack)->a->content = (*stack)->a->next->content;
		(*stack)->a->next->content = tmp;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(1));
}

void	ft_ra(t_stack **stack)
{
	t_list	*last;
	t_list	*tmp;

	if ((*stack)->a->next)
	{
		last = ft_lstlast((*stack)->a);
		tmp = (*stack)->a;
		(*stack)->a = (*stack)->a->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(2));
}

void	ft_rra(t_stack **stack)
{
	t_list	*first;
	t_list	*bf_last;
	t_list	*last;

	if ((*stack)->a->next)
	{
		first = (*stack)->a;
		bf_last = (*stack)->a;
		while (bf_last->next->next)
			bf_last = bf_last->next;
		last = bf_last->next;
		last->next = first;
		bf_last->next = NULL;
		(*stack)->a = last;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(3));
}

void	ft_pb(t_stack **stack)
{
	t_list	*tmp;
	t_list	*swap;

	if (!(*stack)->a)
		return ;
	if ((*stack)->a->next != NULL)
		tmp = (*stack)->a->next;
	else
		tmp = NULL;
	swap = (*stack)->a;
	swap->next = (*stack)->b;
	(*stack)->a = tmp;
	(*stack)->b = swap;
	ft_lstadd_back(&(*stack)->op, ft_lstnew(4));
}
