/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:19 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/03 11:38:27 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sb(t_stack **stack)
{
	int		tmp;

	if (!(*stack)->b || !(*stack)->b->next)
		return ;
	if ((*stack)->b->next)
	{
		tmp = (*stack)->b->content;
		(*stack)->b->content = (*stack)->b->next->content;
		(*stack)->b->next->content = tmp;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(5));
}

void	ft_rb(t_stack **stack)
{
	t_list	*last;
	t_list	*tmp;

	if ((*stack)->b->next)
	{
		last = ft_lstlast((*stack)->b);
		tmp = (*stack)->b;
		(*stack)->b = (*stack)->b->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(6));
}

void	ft_rrb(t_stack **stack)
{
	t_list	*first;
	t_list	*bf_last;
	t_list	*last;

	if ((*stack)->b->next)
	{
		first = (*stack)->b;
		bf_last = (*stack)->b;
		while (bf_last->next->next)
			bf_last = bf_last->next;
		last = bf_last->next;
		last->next = first;
		bf_last->next = NULL;
		(*stack)->b = last;
	}
	ft_lstadd_back(&(*stack)->op, ft_lstnew(7));
}

void	ft_pa(t_stack **stack)
{
	t_list	*tmp;
	t_list	*swap;

	if (!(*stack)->b)
		return ;
	tmp = (*stack)->b->next;
	swap = (*stack)->b;
	swap->next = (*stack)->a;
	(*stack)->b = tmp;
	(*stack)->a = swap;
	ft_lstadd_back(&(*stack)->op, ft_lstnew(8));
}
