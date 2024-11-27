/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:40:19 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/27 15:35:55 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap **a)
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
}

void	rrb(t_push_swap **b)
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
}

void	rrr(t_push_swap **a, t_push_swap **b)
{
	ra(a);
	rb(b);
}
