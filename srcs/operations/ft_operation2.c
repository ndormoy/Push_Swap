/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:44:17 by noedormoy         #+#    #+#             */
/*   Updated: 2021/12/28 10:41:56 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ss(t_stack *stack)
{
	ft_sa(&stack);
	ft_sb(&stack);
	ft_lstadd_back(&(stack)->op, ft_lstnew(9));
}

void	ft_rr(t_stack *stack)
{
	ft_ra(&stack);
	ft_rb(&stack);
	ft_lstadd_back(&(stack)->op, ft_lstnew(10));
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(&stack);
	ft_rrb(&stack);
	ft_lstadd_back(&(stack)->op, ft_lstnew(11));
}
