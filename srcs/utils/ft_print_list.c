/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:41:37 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 12:45:27 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_op(t_list **begin_list)
{
	t_list		*current;
	const char	tab_op[13][5] = {"No\n", "sa\n", "ra\n", "rra\n", "pb\n",
		"sb\n", "rb\n", "rrb\n", "pa\n",
		"ss\n", "rr\n", "rrr\n"};

	current = *begin_list;
	while (current)
	{
		ft_putstr((char *)tab_op[current->content]);
		current = current ->next;
	}
	current = *begin_list;
}
