/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 17:02:41 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap **a)
{
	swap_a(a, 1);
}

void ft_sort(t_push_swap **a, t_push_swap **b)
{
	int len;
	if (ft_sorted(*a, *b))
		return;
	len = length_lst(a);
	if (len == 2)
		sort_two(a);
}