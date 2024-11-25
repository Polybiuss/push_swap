/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/25 19:22:51 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rchunk_numb(t_push_swap **a, t_chunck *chunk)
{
	t_push_swap	*tmp;
	int			i;
	int			res;

	if (!(*a))
		return (-1);
	tmp = (*a);
	i = length_lst(a);
	res = -1;
	while (tmp)
	{
		if (tmp->content >= chunk->start && tmp->content <= chunk->end)
			res = i;
		tmp = tmp->next;
		--i;
	}
	return (res);
}

void	push_rb_chunk(t_push_swap **a, t_push_swap **b, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		reverse_rotate_a(a, 1);
		--i;
	}
	push_b(a, b);
}

void	ft_sort(t_push_swap **a, t_push_swap **b)
{
	t_chunck	*chunk;

	if (ft_sorted(*a, *b))
		return ;
	chunk = create_chunk(a);
	push_chunk(a, b, chunk);
	push_sorted_chunk(a, b, chunk);
	free(chunk->tab_sorted);
	free(chunk);
}
