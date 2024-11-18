/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:17:23 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 13:06:26 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push_swap **a, int bl)
{
	t_push_swap	*tmp;
	t_push_swap	*last;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = (*a)->next;
	while (last->next)
		last = last->next;
	tmp->next = last->next;
	last->next = tmp;
	if (bl)
		ft_putstr_fd("ra\n", 0);
}

void	rotate_b(t_push_swap **b, int bl)
{
	t_push_swap	*tmp;
	t_push_swap	*lst;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	lst = (*b)->next;
	while (lst->next)
		lst = lst->next;
	tmp->next = lst->next;
	lst->next = tmp;
	if (bl)
		ft_putstr_fd("rb\n", 0);
}

void	rotate_rr(t_push_swap **a, t_push_swap **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	ft_putstr_fd("rr\n", 0);
}