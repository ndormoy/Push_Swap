/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:45:54 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/29 18:29:36 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		size_a;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->b = NULL;
	stack->a = NULL;
	stack->op = NULL;
	ft_check_args(argc, argv, &stack);
	convert_args(argc, argv, &stack->a, &stack);
	size_a = ft_lstsize(stack->a);
	ft_process(&stack, size_a);
	ft_optimise(&stack->op);
	ft_optimise_2(&stack->op);
	print_op(&stack->op);
	ft_lstclear(&stack->a, free);
	ft_lstclear(&stack->b, free);
	ft_lstclear(&stack->op, free);
	free(stack);
}
