/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:26:50 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/03 12:05:14 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_push_swap.h"

int	ft_check_op(char *op, t_list **do_op)
{
	int			i;
	const char	tab_op[13][5] = {"No\n", "sa\n", "ra\n", "rra\n", "pb\n",
		"sb\n", "rb\n", "rrb\n", "pa\n",
		"ss\n", "rr\n", "rrr\n"};

	i = 0;
	while (i < 12)
	{
		if (ft_strcmp((char *)tab_op[i], op) == 0 && ft_strcmp("No\n", op) != 0)
		{
			ft_lstadd_back(&(*do_op), ft_lstnew(i));
			return (1);
		}
		i++;
	}
	return (-1);
}

int	ft_check_and_fill(t_stack **stack, t_list **do_op)
{
	char	*ret;

	ret = get_next_line(0);
	while (ret)
	{
		if (ft_check_op(ret, &(*do_op)) == -1)
		{
			free(ret);
			ret = get_next_line(0);
			while (ret)
			{
				free(ret);
				ret = get_next_line(0);
			}
			free(ret);
			ft_clean_stack(&(*stack));
			ft_lstclear(&(*do_op), free);
			ft_error();
			exit(0);
		}
		free(ret);
		ret = get_next_line(0);
	}
	free(ret);
	return (1);
}

void	ft_do_op_utils(t_stack **stack, t_list **do_op)
{
	if ((*do_op)->content == 1)
		ft_sa(&(*stack));
	else if ((*do_op)->content == 2)
		ft_ra(&(*stack));
	else if ((*do_op)->content == 3)
		ft_rra(&(*stack));
	else if ((*do_op)->content == 4)
		ft_pb(&(*stack));
	else if ((*do_op)->content == 5)
		ft_sb(&(*stack));
	else if ((*do_op)->content == 6)
		ft_rb(&(*stack));
	else if ((*do_op)->content == 7)
		ft_rrb(&(*stack));
	else if ((*do_op)->content == 8)
		ft_pa(&(*stack));
	else if ((*do_op)->content == 9)
		ft_ss(&(**stack));
	else if ((*do_op)->content == 10)
		ft_rr(&(**stack));
	else if ((*do_op)->content == 11)
		ft_rrr(&(**stack));
}

void	ft_do_op(t_stack **stack, t_list **do_op)
{
	t_list	*save;

	save = *do_op;
	while ((*do_op))
	{
		ft_do_op_utils(&(*stack), (&(*do_op)));
		*do_op = (*do_op)->next;
	}
	*do_op = save;
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*do_op;

	ft_init(&stack, &do_op);
	ft_check_args(argc, argv, &stack);
	convert_args(argc, argv, &stack->a, &stack);
	ft_check_and_fill(&stack, &do_op);
	ft_do_op(&stack, &do_op);
	if ((ft_all_sorted(stack->a)) == 1 && stack->b == NULL)
	{
		ft_lstclear(&do_op, free);
		ft_clean_stack(&stack);
		ft_putstr("OK\n");
	}
	else
	{
		ft_lstclear(&do_op, free);
		ft_clean_stack(&stack);
		ft_putstr("KO\n");
	}
}
