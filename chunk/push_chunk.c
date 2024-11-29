/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:06:01 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:14:44 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_rotate_b(t_push_swap **b, t_chunck *chunk)
{
	if (!(*b))
		return (0);
	if ((*b)->content < chunk->middle)
		return (1);
	return (0);
}

void	check_b_chunk(t_push_swap **b, t_chunck *chunk)
{
	if ((*b)->content < chunk->middle)
		rotate_b(b, 1);
}

void	push_b_chunk(t_push_swap **a, t_push_swap **b, int in, t_chunck *c)
{
	int	i;
	int	rb;

	i = in;
	rb = is_rotate_b(b, c);
	if (i > 0 && rb == 1)
	{
		rotate_rr(a, b);
		--i;
	}
	else if (rb == 1)
		rotate_b(b, 1);
	while (i)
	{
		rotate_a(a, 1);
		--i;
	}
	push_b(a, b);
}

int	find_chunk_numb(t_push_swap **a, t_chunck *chunk)
{
	t_push_swap	*tmp;
	int			i;

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

void	push_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk)
{
	int	index;

	index = 1;
	if (!(*a))
		return ;
	while ((*a))
	{
		find_start_and_end(a, chunk);
		index = find_chunk_numb(a, chunk);
		if (index == -1)
			return ;
		push_b_chunk(a, b, index, chunk);
	}
	check_b_chunk(b, chunk);
}
