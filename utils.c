/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:50:53 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/18 16:54:40 by jbergos          ###   ########.fr       */
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

void	deploy_all_table(t_push_swap *a, t_push_swap *b)
{
	char *sa;
	char *sb;
	if (!a && !b)
		return ;
	if (a)
	{
		sa = ft_itoa(a->content);
		ft_putstr_fd(sa, 0);
		ft_putstr_fd("  |  ", 0);
		free(sa);
	}
	else
		ft_putstr_fd("   |  ", 0);
	if (b)
	{
		sb = ft_itoa(b->content);
		ft_putstr_fd(sb, 0);
		ft_putstr_fd("\n", 0);
		free(sb);
	}
	else
		ft_putstr_fd(" \n", 0);
	if (!b)
	{
		if (!a)
			return ;
		if (a->next == NULL)
			return ;
		else
			return (deploy_all_table(a->next, NULL));
	}
	else if (!a)
	{
		if (!b)
			return ;
		if (b->next == NULL)
			return ;
		else
			return (deploy_all_table(NULL, b->next));
	}
	else
	{

		if (a->next == NULL && b->next == NULL)
			return ;
		if (b->next == NULL)
			return (deploy_all_table(a->next, NULL));
		if (a->next == NULL)
			return (deploy_all_table(NULL, b->next));
		else
			return (deploy_all_table(a->next, b->next));
	}
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

int length_lst(t_push_swap **a)
{
	if (!(*a))
		return (0);
	return(length_lst(&(*a)->next) + 1);
}

int	somme_lst(t_push_swap **a)
{
	if (!(*a))
		return (0);
	return (somme_lst(&(*a)->next) + (*a)->content);
}

int median_lst(t_push_swap **a)
{
	int somme;
	int length;
	int res;

	somme = somme_lst(a);
	length = length_lst(a);
	res = somme / length;
	return(res);
}
