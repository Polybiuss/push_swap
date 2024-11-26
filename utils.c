/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:50:53 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/26 18:27:29 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_table_char(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
	{
		free(pptr[i]);
		++i;
	}
	free(pptr);
}

long int	ft_atol_modified(char *s)
{
	int			i;
	long int	res;
	long int	n;

	i = 0;
	res = 0;
	n = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			n = -n;
		++i;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += (s[i] - 48);
		++i;
	}
	return (res * n);
}

int	ft_length_tab(char **pstr, int start)
{
	int	len;

	len = 0;
	while (pstr[start])
	{
		++start;
		++len;
	}
	return (len);
}

int	length_lst(t_push_swap **a)
{
	if (!(*a))
		return (0);
	return (length_lst(&(*a)->next) + 1);
}
