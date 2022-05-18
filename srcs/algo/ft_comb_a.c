/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:52:09 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 10:52:13 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_comb_a_one(t_stack **stack)
{
	ft_ra(&(*stack));
	ft_sa(&(*stack));
	ft_rra(&(*stack));
	ft_sa(&(*stack));
}

void	ft_comb_a_two(t_stack **stack)
{
	ft_sa(&(*stack));
	ft_ra(&(*stack));
	ft_sa(&(*stack));
	ft_rra(&(*stack));
}

void	ft_comb_a_three(t_stack **stack)
{
	ft_sa(&(*stack));
	ft_ra(&(*stack));
	ft_sa(&(*stack));
	ft_rra(&(*stack));
	ft_sa(&(*stack));
}

void	ft_comb_a_four(t_stack **stack)
{
	ft_ra(&(*stack));
	ft_sa(&(*stack));
	ft_rra(&(*stack));
}
