/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:36:07 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/26 21:01:25 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap **a)
{
	swap_a(a, 1);
}

void	sort_three(t_push_swap **a)
{
	t_three	*three;

	three = create_three(a);
	if (three->pos_low == 0 && three->pos_high == 2)
		return (free(three->tab), free(three));
	else if (three->pos_low == 0)
		triple_cmd(a);
	else if (three->pos_low == 1 && three->pos_high == 0)
		rotate_a(a, 1);
	else if (three->pos_low == 1 && three->pos_high == 2)
		swap_a(a, 1);
	else if (three->pos_low == 2 && three->pos_high == 0)
	{
		swap_a(a, 1);
		reverse_rotate_a(a, 1);
	}
	else
		reverse_rotate_a(a, 1);
	free(three->tab);
	free(three);
}

void	sort_four(t_push_swap **a, t_push_swap **b)
{
	push_one_low_value(a, b);
	sort_three(a);
	push_a(b, a);
}

void	sort_five(t_push_swap **a, t_push_swap **b)
{
	push_one_low_value(a, b);
	push_one_low_value(a, b);
	sort_three(a);
	push_a(b, a);
	push_a(b, a);
}

void	sort_six(t_push_swap **a, t_push_swap **b)
{
	push_one_low_value(a, b);
	push_one_low_value(a, b);
	push_one_low_value(a, b);
	sort_three(a);
	push_a(b, a);
	push_a(b, a);
	push_a(b, a);
}
