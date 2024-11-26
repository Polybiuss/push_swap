/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:04:27 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/17 14:30:36 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}

int	check_table_is_int(char **table, int start)
{
	while (table[start])
	{
		if (table[start][0] == '+' || table[start][0] == '-')
		{
			if (!ft_str_isdigit((table[start] + 1)))
				return (0);
		}
		else
		{
			if (!ft_str_isdigit((table[start])))
				return (0);
		}
		++start;
	}
	return (1);
}

int	check_untl_lst(t_push_swap *a, int dob)
{
	if (dob == a->content)
		return (0);
	if (!a->next)
		return (1);
	return (check_untl_lst(a->next, dob));
}

int	check_doble_lst(t_push_swap *a)
{
	int	dob;

	dob = a->content;
	if (!a->next)
		return (1);
	if (!check_untl_lst(a->next, dob))
		return (0);
	return (check_doble_lst(a->next));
}
