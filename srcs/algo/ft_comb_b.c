/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:42:59 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 10:43:08 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_comb_b_one(t_stack **stack)
{
	ft_sb(&(*stack));
	ft_rb(&(*stack));
	ft_sb(&(*stack));
	ft_rrb(&(*stack));
	ft_sb(&(*stack));
}

void	ft_comb_b_two(t_stack **stack)
{
	ft_rb(&(*stack));
	ft_sb(&(*stack));
	ft_rrb(&(*stack));
	ft_sb(&(*stack));
}

void	ft_comb_b_three(t_stack **stack)
{
	ft_rb(&(*stack));
	ft_sb(&(*stack));
	ft_rrb(&(*stack));
}

void	ft_comb_b_four(t_stack **stack)
{
	ft_sb(&(*stack));
	ft_rb(&(*stack));
	ft_sb(&(*stack));
	ft_rrb(&(*stack));
}
