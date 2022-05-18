/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:40:48 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/23 18:52:54 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_2numbers(t_stack *stack)
{
	if (stack->a->content > stack->a->next->content)
		ft_sa(&(stack));
}

void	ft_3numbers(t_stack **stack)
{
	int	n0;
	int	n1;
	int	n2;

	n0 = (*stack)->a->content;
	n1 = (*stack)->a->next->content;
	n2 = (*stack)->a->next->next->content;
	if (n0 == n1 && n0 == n2)
		return ;
	else if (n0 > n1 && n0 < n2 && n1 < n2)
		ft_sa(&(*stack));
	else if (n0 <= n1 && n0 >= n2 && n1 >= n2)
		ft_rra(&(*stack));
	else if (n0 >= n1 && n0 >= n2 && n1 <= n2)
		ft_ra(&(*stack));
	else if (n0 > n1 && n1 > n2)
	{
		ft_ra(&(*stack));
		ft_sa(&(*stack));
	}
	else if (n0 < n1 && n0 < n2 && n1 > n2)
	{
		ft_rra(&(*stack));
		ft_sa(&(*stack));
	}
}

void	ft_5less(t_stack **stack)
{
	int	bigger;
	int	smaller;
	int	size_b;

	bigger = ft_bigger((*stack)->a);
	smaller = ft_smaller((*stack)->a);
	while (ft_lstsize((*stack)->a) != 3)
	{
		if ((*stack)->a->content == bigger || (*stack)->a->content == smaller)
			ft_pb(&(*stack));
		else
			ft_rra(&(*stack));
	}
	size_b = ft_lstsize((*stack)->b);
	ft_3numbers(&(*stack));
	if (size_b == 2)
		if (((*stack)->b->content > (*stack)->b->next->content))
			ft_sb(&(*stack));
	if (size_b == 2)
		ft_pa(&(*stack));
	ft_pa(&(*stack));
	if ((*stack)->a->content > (*stack)->a->next->content)
		ft_ra(&(*stack));
}

void	ft_process(t_stack **stack, int size_a)
{
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		ft_2numbers((*stack));
	else if (ft_all_sorted((*stack)->a) == 1)
		return ;
	else if (size_a == 3)
		ft_3numbers(&(*stack));
	else if (size_a <= 5)
		ft_5less(&(*stack));
	else if (size_a > 5)
		ft_sort_a_to_b(*stack, ft_lstsize((*stack)->a));
}
