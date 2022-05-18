/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:45:38 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 18:29:10 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_2numbers_b(t_stack *stack)
{
	if (stack->b->content < stack->b->next->content)
		ft_sb(&(stack));
}

void	ft_3numbers_b(t_stack **stack)
{
	int	n0;
	int	n1;
	int	n2;

	n0 = (*stack)->b->content;
	n1 = (*stack)->b->next->content;
	n2 = (*stack)->b->next->next->content;
	if (n0 < n1 && n1 < n2)
		ft_comb_b_one(&(*stack));
	else if (n0 > n1 && n0 < n2 && n1 < n2)
		ft_comb_b_two(&(*stack));
	else if (n0 < n1 && n0 > n2 && n1 > n2)
		ft_sb(&(*stack));
	else if (n0 > n1 && n0 > n2 && n1 < n2)
		ft_comb_b_three(&(*stack));
	else if (n0 < n1 && n0 < n2 && n1 > n2)
		ft_comb_b_four(&(*stack));
}

int	ft_process_b(t_stack *stack, int len_lst)
{
	if (len_lst == 1)
		return (1);
	else if (len_lst == 2)
		ft_2numbers_b(stack);
	else if (len_lst == 3)
		ft_3numbers_b(&(stack));
	return (1);
}
