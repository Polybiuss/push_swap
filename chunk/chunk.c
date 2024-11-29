/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:05:28 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:12:06 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_start(t_push_swap **a, t_chunck *chunk)
{
	t_push_swap	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->content >= chunk->start && tmp->content <= chunk->middle)
			return ;
		tmp = tmp->next;
	}
	chunk->start = new_start(chunk);
}

void	find_end(t_push_swap **a, t_chunck *chunk)
{
	t_push_swap	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->content <= chunk->end && tmp->content >= chunk->middle)
			return ;
		tmp = tmp->next;
	}
	chunk->end = new_end(chunk);
}

void	find_start_and_end(t_push_swap **a, t_chunck *chunk)
{
	find_start(a, chunk);
	find_end(a, chunk);
}

t_chunck	*create_chunk(t_push_swap **a)
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
	chunck->down = 0;
	return (chunck);
}
