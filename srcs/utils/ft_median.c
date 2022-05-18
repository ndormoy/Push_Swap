/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:44:12 by noedormoy         #+#    #+#             */
/*   Updated: 2021/12/28 18:35:19 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_list_to_tab(t_list *lst, int size)
{
	int	*tab;
	int	i;

	i = 0;
	if (!lst || size == 0)
		return (NULL);
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	while (lst && i < size)
	{
		tab[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (tab);
}

int	ft_get_median(t_list *lst, int size, t_stack **stack)
{
	int		median;
	int		*tab;

	tab = ft_list_to_tab(lst, size);
	if (!tab)
	{
		ft_clean_stack(&(*stack));
		ft_error();
	}
	ft_sort_tab(&(*tab), size);
	median = tab[size / 2];
	free(tab);
	return (median);
}
