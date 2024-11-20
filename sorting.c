/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/20 21:41:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

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
	int	*tab;
	t_push_swap *tmp;
	int	i;
	int	pivot;

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

int *tab_sorted(t_push_swap **a, int len)
{
	int	*tab_sorted;
	t_push_swap	*tmp;
	int i;

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

int	wish_n(int len)
{
	if (len <= 10)
		return (5);
	else if (len <= 150)
		return (8);
	else
		return (18);
}

int	find_middle(int *tab, int len)
{
	return (tab[len / 2]);
}

t_chunck *create_chunk(t_push_swap **a)
{
	t_chunck	*chunck;

	chunck = malloc(sizeof(t_chunck));
	if (!chunck)
		return (NULL);
	chunck->len = length_lst(a);
	chunck->n = wish_n(chunck->len);
	chunck->tab_sorted = tab_sorted(a, chunck->len);
	chunck->middle = find_middle(chunck->tab_sorted, chunck->len);
	chunck->offset = chunck->len / chunck->n;
	chunck->start = chunck->tab_sorted[chunck->len / 2 - chunck->offset];
	chunck->end = chunck->tab_sorted[chunck->len / 2 + chunck->offset];
	return (chunck); 
}

void	ft_sort(t_push_swap **a, t_push_swap **b)
{
	t_chunck *chunk;
	
	if (ft_sorted(*a, *b))
		return;
	chunk = create_chunk(a);
	printf("len : %d\n", chunk->len);
	printf("n : %d\n", chunk->n);
	printf("middle : %d\n", chunk->middle);
	printf("offset : %d\n", chunk->offset);
	printf("start : %d\n", chunk->start);
	printf("end : %d\n", chunk->end);
	int i = 0;
	while (i < chunk->len)
	{
		printf("teb :%d\n", chunk->tab_sorted[i]);
		++i;
	}
}