/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:41:28 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/28 19:16:34 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_clean_tab2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_clean_stack(t_stack **stack)
{
	ft_lstclear(&(*stack)->a, free);
	ft_lstclear(&(*stack)->b, free);
	ft_lstclear(&(*stack)->op, free);
	free(*stack);
}
