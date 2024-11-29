/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:17:23 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:15:39 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_queue(t_push_swap **a, t_push_swap **b, t_chunck *chunk)
{
	if (chunk->down == 0 || !(*a))
	{
		push_a(b, a);
		rotate_a(a, 1);
		chunk->down += 1;
	}
	else if (chunk->down != 0)
	{
		if ((*b)->content < last_value(a))
			rotate_b(b, 1);
		else
		{
			push_a(b, a);
			rotate_a(a, 1);
			chunk->down += 1;
		}
	}
}

void	to_aa(t_push_swap **a, t_push_swap **b, int index, t_chunck *chunk)
{
	int	i;

	i = index;
	while (i > 0)
	{
		push_to_queue(a, b, chunk);
		--i;
	}
	push_a(b, a);
}

void	chuck_down(t_push_swap **a, t_chunck *chunk)
{
	reverse_rotate_a(a, 1);
	chunk->down -= 1;
}
