/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:40:19 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 11:40:48 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_push_swap **a, int bl)
{
	t_push_swap	*tmp;
	t_push_swap	*lst;

	if (!(*a) || !(*a)->next)
		return ;
	lst = *a;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = lst->next;
	lst->next = *a;
	*a = lst;
	if (bl)
		ft_putstr_fd("rra\n", 0);
}

void	reverse_rotate_b(t_push_swap **b, int bl)
{
	t_push_swap	*tmp;
	t_push_swap	*lst;

	if (!(*b) || !(*b)->next)
		return ;
	lst = *b;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = lst->next;
	lst->next = *b;
	*b = lst;
	if (bl)
		ft_putstr_fd("rrr\n", 0);
}

void	reverse_rotate_r(t_push_swap **a, t_push_swap **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_putstr_fd("rrr\n", 0);
}
