/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:49:02 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 10:58:08 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init(t_stack **stack, t_list **do_op)
{
	*stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_error();
		exit(0);
	}
	(*stack)->b = NULL;
	(*stack)->a = NULL;
	(*stack)->op = NULL;
	(*do_op) = NULL;
}
