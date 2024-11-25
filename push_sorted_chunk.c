/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sorted_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:12:43 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/25 19:22:56 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_value(t_push_swap **a)
{
	t_push_swap	*tmp;

	tmp = (*a);
	while (tmp)
	{
		if (!tmp->next)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

void	to_ra(t_push_swap **a, t_push_swap**b, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		reverse_rotate_b(b, 1);
		--i;
	}
	push_a(b, a);
}

int	find_chunk_numb_b(t_push_swap **b, int find)
{
	t_push_swap	*tmp;
	int			i;

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
	int			i;

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

void	push_sorted_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk)
{
	int	nb;
	int	index;
	int	r_index;

	index = 1;
	r_index = 1;
	nb = chunk->len - 1;
	if (!(*b))
		return ;
	while (nb >= 0)
	{
		index = find_chunk_numb_b(b, chunk->tab_sorted[nb]);
		r_index = find_rchunk_numb_b(b, chunk->tab_sorted[nb]);
		if (chunk->tab_sorted[nb] == last_value(a))
			chuck_down(a, chunk);
		else if (index == -1 && r_index == -1)
			return ;
		else if (index < r_index)
			to_aa(a, b, index, chunk);
		else
			to_ra(a, b, r_index);
		--nb;
	}
}
