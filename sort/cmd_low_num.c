/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_low_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:40:24 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:14:01 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	top_lst_low(t_push_swap **a)
{
	t_push_swap	*tmp;
	int			val;

	tmp = (*a);
	val = tmp->content;
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp)
			return (1);
		if (val > tmp->content)
			return (0);
	}
	return (0);
}

void	triple_cmd(t_push_swap **a)
{
	rotate_a(a, 1);
	swap_a(a, 1);
	reverse_rotate_a(a, 1);
}

void	to_a_low_num(t_push_swap **a, t_push_swap **b, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		rotate_a(a, 1);
		--i;
	}
	push_b(a, b);
}

void	to_ra_low_num(t_push_swap **a, t_push_swap **b, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		reverse_rotate_a(a, 1);
		--i;
	}
	push_b(a, b);
}

void	push_one_low_value(t_push_swap **a, t_push_swap **b)
{
	t_low_value	*low_val;
	int			index;
	int			r_index;

	low_val = create_low(a);
	index = low_val->pos_low;
	r_index = (low_val->len - low_val->pos_low);
	if (index <= r_index)
		to_a_low_num(a, b, index);
	else
		to_ra_low_num(a, b, r_index);
	free(low_val->tab);
	free(low_val);
}
