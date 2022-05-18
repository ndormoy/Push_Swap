/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:14:57 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 18:25:52 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_empty_arg(char **argv)
{
	int	i;
	int	j;
	int	ok;

	i = 1;
	while (argv[i])
	{
		j = 0;
		ok = -1;
		while (argv[i][j])
		{
			if (*argv[i] == '\0')
				ok = -1;
			else if (argv[i][j] != ' ')
				ok = 1;
			j++;
		}
		i++;
		if (ok == -1)
			break ;
	}
	if (ok == -1)
		return (-1);
	else
		return (1);
}

int	ft_check_big_letter(char **argv, t_stack **stack)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j], j) == 0 || ft_is_space(argv[i][j]) == 1)
			{
				ft_clean_stack(&(*stack));
				ft_error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_int_max_big(char **argv, t_stack **stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
		{
			ft_clean_stack(&(*stack));
			ft_error();
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_double_big(char **argv, t_stack **stack)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
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

int	ft_check_big_args(int argc, char **argv, t_stack **stack)
{
	if (argc == 1)
	{
		ft_clean_stack(&(*stack));
		exit(0);
	}
	ft_check_big_letter(argv, &(*stack));
	ft_check_int_max_big(argv, &(*stack));
	ft_check_double_big(argv, &(*stack));
	return (0);
}
