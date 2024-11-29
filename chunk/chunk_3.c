/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:01:05 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:12:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	middle_lst(t_push_swap **a, int len)
{
	int			*tab;
	t_push_swap	*tmp;
	int			i;
	int			pivot;

	tab = malloc(sizeof(int *) * (len));
	if (!tab)
		return (0);
	tmp = (*a);
	i = 0;
	while ((tmp))
	{
		tab[i] = tmp->content;
		++i;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, len);
	pivot = tab[len / 2];
	free(tab);
	return (pivot);
}

int	*tab_sorted(t_push_swap **a, int len)
{
	int			*tab_sorted;
	t_push_swap	*tmp;
	int			i;

	tab_sorted = malloc(sizeof(int) * len);
	if (!tab_sorted)
		return (0);
	tmp = (*a);
	i = 0;
	while (tmp)
	{
		tab_sorted[i] = tmp->content;
		tmp = tmp->next;
		++i;
	}
	ft_sort_int_tab(tab_sorted, len);
	return (tab_sorted);
}
