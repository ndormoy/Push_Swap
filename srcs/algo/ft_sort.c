/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:44:39 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 18:36:02 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_b_to_a(t_stack *stack, int *pushed, int *rotate, int size)
{
	int	median;
	int	i;

	i = 0;
	median = ft_get_median(stack->b, size, &stack);
	while (i++ < size && is_nb_above_med_in_b(stack, size, median) == 1)
	{
		if (stack->b->content > median)
		{
			ft_pa(&(stack));
			*pushed += 1;
		}
		else
		{
			ft_rb(&(stack));
			*rotate += 1;
		}
	}
}

int	ft_sort_b_to_a(t_stack *stack, int size)
{
	int	rotate;
	int	pushed;
	int	replace;

	replace = 0;
	rotate = 0;
	pushed = 0;
	if (size <= 3)
	{
		ft_process_b(stack, size);
		return (1);
	}
	ft_push_b_to_a(stack, &pushed, &rotate, size);
	ft_rotate_to_original_position_b(&stack, rotate);
	if (ft_all_sorted(stack->a) == -1)
		ft_sort_a_to_b(stack, pushed);
	if (ft_all_inv_sorted(stack->b) == -1)
		ft_sort_b_to_a(stack, size - pushed);
	while (replace++ < pushed)
		ft_pb(&(stack));
	return (1);
}

void	ft_push_a_to_b(t_stack *stack, int *pushed, int *rotate, int size)
{
	int	median;
	int	i;

	i = 0;
	median = ft_get_median(stack->a, size, &stack);
	while (i++ < size && is_nb_under_med_in_a(stack, size, median) == 1)
	{
		if (stack->a->content < median)
		{
			ft_pb(&(stack));
			*pushed += 1;
		}
		else
		{
			ft_ra(&(stack));
			*rotate += 1;
		}
	}
}

int	ft_sort_a_to_b(t_stack *stack, int size)
{
	int	rotate;
	int	pushed;
	int	replace;

	replace = 0;
	rotate = 0;
	pushed = 0;
	if (size <= 3)
	{
		ft_process_a(&stack, size);
		return (1);
	}
	ft_push_a_to_b(stack, &pushed, &rotate, size);
	ft_rotate_to_original_position_a(&stack, rotate);
	if (ft_all_sorted(stack->a) == -1)
		ft_sort_a_to_b(&(*stack), size - pushed);
	if (ft_all_inv_sorted(stack->b) == -1)
		ft_sort_b_to_a(stack, pushed);
	while (replace++ < pushed)
		ft_pa(&(stack));
	return (1);
}
