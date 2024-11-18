/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 21:27:46 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap **a)
{
	swap_a(a, 1);
}

void	check_b_sort_10(t_push_swap **b)
{
	if (!(*b)->next)
		return ;
	if ((*b)->content < (*b)->next->content)
		swap_b(b, 1);
}

void	pivot_10(t_push_swap **a, t_push_swap **b, int pivot)
{
	int	i;

	i = 0;
	while (i++ < pivot)
	{
		push_b(a, b);
		check_b_sort_10(b);
	}
}

void	sort_10(t_push_swap **a, t_push_swap **b, int len)
{
	pivot_10(a, b, len / 2);
}

void ft_sort(t_push_swap **a, t_push_swap **b)
{
	int len;
	if (ft_sorted(*a, *b))
		return;
	len = length_lst(a);
	if (len == 2)
		sort_two(a);
	if(len < 10 && len > 2)
		sort_10(a, b, len);
}