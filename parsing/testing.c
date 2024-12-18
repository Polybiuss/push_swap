/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:19:59 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:09:52 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorted(t_push_swap *a, t_push_swap *b)
{
	int			sort;
	t_push_swap	*tmp;

	if (b)
		return (0);
	if (!a)
		return (0);
	tmp = a;
	sort = a->content;
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp)
			break ;
		if (sort > tmp->content)
			return (0);
		sort = tmp->content;
	}
	return (1);
}
/*
void	testing_cmd(t_push_swap **a, t_push_swap **b)
{
	char cmd[4];
	int	i = 1;
	while (i)
	{
		scanf("%s", cmd);
		if (!ft_strncmp(cmd, "sa", 2))
			swap_a(a, 1);
		else if (!ft_strncmp(cmd, "sb", 2))
			swap_b(b, 1);
		else if (!ft_strncmp(cmd, "ss", 2))
			swap_s(a, b);
		else if (!ft_strncmp(cmd, "pa", 2))
			push_a(b, a);
		else if (!ft_strncmp(cmd, "pb", 2))
			push_b(a, b);
		else if (!ft_strncmp(cmd, "ra", 2))
			rotate_a(a, 1);
		else if (!ft_strncmp(cmd, "rb", 2))
			rotate_b(b, 1);
		else if (!ft_strncmp(cmd, "rra", 3))
			reverse_rotate_a(a, 1);
		else if (!ft_strncmp(cmd, "rrb", 3))
			reverse_rotate_b(b, 1);
		else if (!ft_strncmp(cmd, "rrr", 3))
			reverse_rotate_r(a, b);
		else if (!ft_strncmp(cmd, "rr", 2))
			rotate_rr(a, b);
		else if (!ft_strncmp(cmd, "c", 1))
			i = 0;
		if (ft_sorted(*a ,*b))
		{
			ft_putstr_fd("Congatulations !!\n", 0);
			return ;
		}
	}
}*/