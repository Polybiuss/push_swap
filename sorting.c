/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/21 17:59:11 by jbergos          ###   ########.fr       */
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

int	find_chunk_numb(t_push_swap **a, t_chunck *chunk)
{
	t_push_swap *tmp;
	int i;

	if (!(*a))
		return (-1);
	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->content >= chunk->start && tmp->content <= chunk->end)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (-1);
}

void	push_b_chunk(t_push_swap **a, t_push_swap **b, int index)
{
	int i;
	i = index;
	while (i)
	{
		rotate_a(a, 1);
		--i;
	}
	push_b(a, b);
}

void	check_b_chunk(t_push_swap **b, t_chunck *chunk)
{
	// (void)chunk;
	// printf("chunck_middle : %d\n", chunk->middle);
	// printf("b value %d\n", (*b)->content);
	if ((*b)->content < chunk->middle)
		rotate_b(b , 1);
	// return ;
}

void	push_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk)
{
	int	index;

	index = 1;
	if (!(*a))
		return ;
	while (index != -1)
	{
		index = find_chunk_numb(a, chunk);
		if (index == -1)
			return ;
		push_b_chunk(a, b, index);
		check_b_chunk(b, chunk);
	}
}

int	new_start(t_chunck *chunk)
{
	int i;

	i = 0;
	while (i < chunk->len)
	{
		if (chunk->start == chunk->tab_sorted[i])
			break;
		++i;
	}
	if (i - chunk->offset <0)
		return (chunk->tab_sorted[0]);
	else
		return (chunk->tab_sorted[i - chunk->offset]);

}

int new_end(t_chunck *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->len)
	{
		if (chunk->end == chunk->tab_sorted[i])
			break;
		++i;
	}
	if (i + chunk->offset > chunk->len -1)
		return (chunk->tab_sorted[chunk->len - 1]);
	else
		return (chunk->tab_sorted[i + chunk->offset]);
}

int	find_chunk_numb_b(t_push_swap **b, int find)
{
	t_push_swap *tmp;
	int	i;

	if (!(*b))
		return (-1);
	tmp = (*b);
	i = 0;
	while (tmp)
	{
		if (tmp->content == find)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (-1);
}

int	find_rchunk_numb_b(t_push_swap **b, int find)
{
	t_push_swap	*tmp;
	int	i;

	if (!(*b))
		return (-1);
	tmp = (*b);
	i = length_lst(b);
	while (tmp)
	{
		if (tmp->content == find)
			return (i);
		tmp = tmp->next;
		--i;
	}
	return (-1);
}

void	to_a(t_push_swap **a, t_push_swap **b, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		rotate_b(b, 1);
		--i;
	}
	push_a(b, a);
}

void	to_ra(t_push_swap **a, t_push_swap**b, int index)
{
	int i;

	i = index;
	while (i > 0)
	{
		reverse_rotate_b(b, 1);
		--i;
	}
	push_a(b, a);
}

void	push_sorted_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk)
{
	int	nb;
	int	index;
	int r_index;

	index = 1;
	r_index = 1;
	nb = chunk->len - 1;
	if (!(*b))
		return ;
	while (index != -1 && nb >= 0 && r_index != -1)
	{
		index = find_chunk_numb_b(b, chunk->tab_sorted[nb]);
		r_index = find_rchunk_numb_b(b, chunk->tab_sorted[nb]);
		if (index == -1 || r_index == -1)
			return ;
		if (index < r_index)
			to_a(a, b, index);
		else
			to_ra(a, b, r_index);
		--nb;
	}
}

void	ft_sort(t_push_swap **a, t_push_swap **b)
{
	t_chunck *chunk;
	
	if (ft_sorted(*a, *b))
		return;
	chunk = create_chunk(a);
	while ((*a))
	{
	push_chunk(a, b, chunk);
	chunk->start = new_start(chunk);
	chunk->end = new_end(chunk);
	}
	push_sorted_chunk(a, b, chunk);
	free(chunk->tab_sorted);
	free(chunk);
}