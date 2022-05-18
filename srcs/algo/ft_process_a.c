/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:45:35 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 10:36:31 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_2numbers_a(t_stack *stack)
{
	if (stack->a->content > stack->a->next->content)
		ft_sa(&(stack));
}

void	ft_3numbers_a(t_stack **stack)
{
	int	n0;
	int	n1;
	int	n2;

	n0 = (*stack)->a->content;
	n1 = (*stack)->a->next->content;
	n2 = (*stack)->a->next->next->content;
	if (n0 > n1 && n0 < n2 && n1 < n2)
		ft_sa(&(*stack));
	else if (n0 < n1 && n0 > n2 && n1 > n2)
		ft_comb_a_one(&(*stack));
	else if (n0 > n1 && n0 > n2 && n1 < n2)
		ft_comb_a_two(&(*stack));
	else if (n0 > n1 && n1 > n2)
		ft_comb_a_three(&(*stack));
	else if (n0 < n1 && n0 < n2 && n1 > n2)
		ft_comb_a_four(&(*stack));
}

void	ft_process_a(t_stack **stack, int size_a)
{
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		ft_2numbers_a(*stack);
	else if (ft_all_sorted((*stack)->a) == 1)
		return ;
	else if (size_a == 3)
		ft_3numbers_a(&(*stack));
}
