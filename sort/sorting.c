/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:17:14 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_low_numb(t_push_swap **a, t_push_swap **b, int len)
{
	if (len == 2)
		sort_two(a);
	if (len == 3)
		sort_three(a);
	if (len == 4)
		sort_four(a, b);
	if (len == 5)
		sort_five(a, b);
	if (len == 6)
		sort_six(a, b);
}

void	ft_sort(t_push_swap **a, t_push_swap **b)
{
	t_chunck	*chunk;

	if (ft_sorted(*a, *b))
		return ;
	if (length_lst(a) <= 6)
		sort_low_numb(a, b, length_lst(a));
	else
	{
		chunk = create_chunk(a);
		push_chunk(a, b, chunk);
		push_sorted_chunk(a, b, chunk);
		free(chunk->tab_sorted);
		free(chunk);
	}
}
