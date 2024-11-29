/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:56:32 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:12:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	new_start(t_chunck *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->len)
	{
		if (chunk->start == chunk->tab_sorted[i])
			break ;
		++i;
	}
	if (i - chunk->offset < 0)
		return (chunk->tab_sorted[0]);
	else
		return (chunk->tab_sorted[i - chunk->offset]);
}

int	new_end(t_chunck *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->len)
	{
		if (chunk->end == chunk->tab_sorted[i])
			break ;
		++i;
	}
	if (i + chunk->offset > chunk->len -1)
		return (chunk->tab_sorted[chunk->len - 1]);
	else
		return (chunk->tab_sorted[i + chunk->offset]);
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
