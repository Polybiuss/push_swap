/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:17:23 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 17:56:24 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_push_swap **a)
{
	t_push_swap	*tmp;
	t_push_swap	*last;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rb(t_push_swap **b)
{
	t_push_swap	*tmp;
	t_push_swap	*lst;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	lst = *b;
	while (lst->next)
		lst = lst->next;
	tmp->next = NULL;
	lst->next = tmp;
}

void	rr(t_push_swap **a, t_push_swap **b)
{
	ra(a);
	rb(b);
}
