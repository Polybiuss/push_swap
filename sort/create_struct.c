/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:28:33 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:14:20 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos_low(int *tab, int len)
{
	int	i;
	int	low;

	i = 0;
	low = tab[i];
	while (i < len)
	{
		if (tab[i] < low)
			low = tab[i];
		++i;
	}
	i = 0;
	while (i < len)
	{
		if (tab[i] == low)
			break ;
		++i;
	}
	return (i);
}

int	find_pos_high(int *tab, int len)
{
	int	i;
	int	high;

	i = 0;
	high = tab[i];
	while (i < len)
	{
		if (tab[i] > high)
			high = tab[i];
		++i;
	}
	i = 0;
	while (i < len)
	{
		if (tab[i] == high)
			break ;
		++i;
	}
	return (i);
}

int	*tab_three(t_push_swap **a, int len)
{
	int			*tab;
	int			i;
	t_push_swap	*tmp;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	i = 0;
	tmp = (*a);
	while (i < len)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (tab);
}

t_three	*create_three(t_push_swap **a)
{
	t_three	*three;

	three = malloc(sizeof(t_three));
	if (!three)
		return (NULL);
	three->len = length_lst(a);
	three->tab = tab_three(a, three->len);
	three->pos_low = find_pos_low(three->tab, three->len);
	three->pos_high = find_pos_high(three->tab, three->len);
	return (three);
}

t_low_value	*create_low(t_push_swap **a)
{
	t_low_value	*low_val;

	low_val = malloc(sizeof(t_low_value));
	if (!low_val)
		return (NULL);
	low_val->len = length_lst(a);
	low_val->tab = tab_three(a, low_val->len);
	low_val->pos_low = find_pos_low(low_val->tab, low_val->len);
	return (low_val);
}
