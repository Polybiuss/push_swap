/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:04:08 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 19:01:19 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push_swap **a, int bl)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (bl)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_push_swap **b, int bl)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	if (bl)
		ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_push_swap **a, t_push_swap **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_putstr_fd("ss\n", 1);
}
