/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:50:53 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/17 14:30:23 by jbergos          ###   ########.fr       */
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

void	deploy_table(t_push_swap **a)
{
	char	*s;

	if (!*a)
		return ;
	s = ft_itoa((*a)->content);
	ft_putstr_fd(s, 0);
	free(s);
	ft_putchar_fd('\n', 0);
	if ((*a)->next == NULL)
		return ;
	return (deploy_table(&(*a)->next));
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
