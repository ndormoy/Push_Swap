/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:15:37 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 18:25:38 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
//remove
#include <stdio.h>

int	ft_check_double_two(char **strs, t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = i + 1;
		while (strs[j])
		{
			if (ft_atoi(strs[i]) == ft_atoi(strs[j]))
			{
				ft_clean_tab2d(strs);
				ft_clean_stack(&(*stack));
				ft_error();
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_letter_two(char **strs, t_stack **stack)
{
	int		i;
	int		j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_isdigit(strs[i][j], j) == 0)
			{
				ft_clean_tab2d(strs);
				ft_clean_stack(&(*stack));
				ft_error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_int_max_two(char **strs, t_stack **stack)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (ft_atoll(strs[i]) > 2147483647 || ft_atoll(strs[i]) < -2147483648)
		{
			ft_clean_tab2d(strs);
			ft_clean_stack(&(*stack));
			ft_error();
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_two_args(char **argv, t_stack **stack)
{
	char	**strs;

	strs = ft_split(argv[1], ' ');
	if (!strs)
	{
		ft_clean_stack(&(*stack));
		ft_error();
		exit(0);
	}
	ft_check_int_max_two(strs, &(*stack));
	ft_check_letter_two(strs, &(*stack));
	ft_check_double_two(strs, &(*stack));
	ft_clean_tab2d(strs);
	return (0);
}

int	ft_check_args(int argc, char **argv, t_stack **stack)
{
	if (argc == 1)
	{
		ft_clean_stack(&(*stack));
		exit(0);
		return (0);
	}
	if (ft_check_empty_arg(argv) == -1)
	{
		ft_clean_stack(&(*stack));
		ft_error();
		exit(0);
	}
	if (argc == 2)
		ft_check_two_args(argv, &(*stack));
	if (argc > 2)
		ft_check_big_args(argc, argv, &(*stack));
	return (0);
}
