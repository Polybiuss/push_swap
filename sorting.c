/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:34 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/19 19:20:44 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap **a)
{
	swap_a(a, 1);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	pivot_lst(t_push_swap **a)
{
	int	*tab;
	int lenght;
	t_push_swap *tmp;
	int	i;
	int	pivot;

	lenght = length_lst(a);
	tab = malloc(sizeof(int *) * (length_lst(a)));
	if (!tab)
		return (0);
	tmp = (*a);
	i = 0;
	while ((tmp))
	{
		tab[i] = tmp->content;
		++i;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, lenght);
	pivot = tab[lenght / 2];
	free(tab);
	return (pivot);
}
int	pivot_to_b(t_push_swap **a, int pivot)
{
	int	i;
	t_push_swap *tmp;

	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->content < pivot)
			return (++i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	pivot_reverse_to_b(t_push_swap **a, int pivot)
{
	int i;
	t_push_swap *tmp;
	int occ;

	tmp = (*a);
	i = 0;
	occ = 0;
	while (tmp)
	{
		if (tmp->content < pivot)
			occ = ++i;
		tmp = tmp->next;
		++i;
	}
	if (!occ)
		return (occ);
	return (i - occ);
}

void	rro_swap(t_push_swap **a, t_push_swap **b, int rs)
{
	while (rs)
	{
		reverse_rotate_a(a, 1);
		--rs;
	}
	push_b(a, b);
}

void	ro_swap(t_push_swap **a, t_push_swap **b, int s)
{
	while (s)
	{
		rotate_a(a, 1);
		--s;
	}
	push_b(a, b);
}

void	ft_pivottage(t_push_swap **a, t_push_swap **b, int pivot)
{
	int s;
	int rs;
	// (void)b;
	// printf("first value %d\n",pivot_to_b(a, pivot));
	// printf("first reverse value %d\n",pivot_reverse_to_b(a, pivot));
	s = pivot_to_b(a, pivot);
	rs = pivot_reverse_to_b(a, pivot);
	if (s == 0 || rs == 0)
		return ;
	else if (rs <= s)
		rro_swap(a, b, rs);
	else if (s < rs)
		ro_swap(a, b, s);
	return(ft_pivottage(a, b, pivot));	
}

void	sort_6(t_push_swap **a, t_push_swap **b)
{
	int	pivot;
	
	pivot = pivot_lst(a);
	ft_pivottage(a, b, pivot);
	// ft_pivottage(a, b, pivot);
	// ft_pivottage(a, b, pivot);
	// ft_pivottage(a, b, pivot);
	
}

void	ft_sort(t_push_swap **a, t_push_swap **b)
{
	int len;
	if (ft_sorted(*a, *b))
	{
		printf("wtf\n");
		return;
	}
	len = length_lst(a);
	if (len == 2)
		sort_two(a);
	else if (len <= 6)
		sort_6(a, b);
}