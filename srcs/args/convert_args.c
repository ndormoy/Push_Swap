/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:40:21 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 14:28:24 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*convert_big_args(int argc, char **argv, t_list **lst)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&(*lst), ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (*lst);
}

t_list	*ft_split_two_arg(char *tab, t_list **lst, t_stack **stack)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(tab, ' ');
	if (!strs)
	{
		ft_clean_stack(&(*stack));
		ft_error();
		exit(0);
	}
	while (strs[i])
	{
		ft_lstadd_back(&(*lst), ft_lstnew(ft_atoi(strs[i])));
		i++;
	}
	ft_clean_tab2d(strs);
	return (*lst);
}

t_list	*convert_two_args(int argc, char **argv, t_list **lst, t_stack **stack)
{
	int		i;

	if (argc == 1)
		return (NULL);
	i = 1;
	ft_split_two_arg(argv[i], &(*lst), &(*stack));
	return (*lst);
}

void	convert_args(int argc, char **argv, t_list **lst, t_stack **stack)
{
	if (argc == 1)
	{
		ft_clean_stack(&(*stack));
		exit(0);
		return ;
	}
	if (argc == 2)
		convert_two_args(argc, argv, lst, &(*stack));
	else
		convert_big_args(argc, argv, lst);
}
