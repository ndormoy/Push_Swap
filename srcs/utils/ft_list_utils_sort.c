/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:38:12 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 11:37:14 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_nb_under_med_in_a(t_stack *stack, int length, int median)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->a;
	while (tmp && i < length)
	{
		if (tmp->content < median)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	is_nb_above_med_in_b(t_stack *stack, int length, int median)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->b;
	while (tmp && i < length)
	{
		if (tmp->content > median)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	ft_rotate_to_original_position_a(t_stack **stack, int rotate)
{
	int	i;

	i = 0;
	if (rotate <= ft_lstsize((*stack)->a) / 2)
	{
		while (i < rotate)
		{
			ft_rra(&(*stack));
			i++;
		}
	}
	else
	{
		rotate = ft_lstsize((*stack)->a) - rotate;
		while (i < rotate)
		{
			ft_ra(&(*stack));
			i++;
		}
	}
}

void	ft_rotate_to_original_position_b(t_stack **stack, int rotate)
{
	int	i;

	i = 0;
	if (rotate <= ft_lstsize((*stack)->b) / 2)
	{
		while (i < rotate)
		{
			ft_rrb(&(*stack));
			i++;
		}
	}
	else
	{
		rotate = ft_lstsize((*stack)->b) - rotate;
		while (i < rotate)
		{
			ft_rb(&(*stack));
			i++;
		}
	}
}
