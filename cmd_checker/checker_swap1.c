/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:04:08 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 17:56:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_push_swap **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
}

void	sb(t_push_swap **b)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
}

void	ss(t_push_swap **a, t_push_swap **b)
{
	sa(a);
	sb(b);
}
