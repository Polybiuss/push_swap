/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:47:58 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/27 16:37:59 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_line(t_push_swap **a, t_push_swap **b)
{
	char	*cmd;
	int		i;

	i = 1;
	cmd = get_next_line(0);
	while (i != -1 && cmd)
	{
		i = get_cmd(a, b, cmd);
		free(cmd);
		if (i == -1)
			break ;
		cmd = get_next_line(0);
	}
	if (!cmd)
		free(cmd);
	get_next_line(-1);
	if (i == -1)
		ft_putstr_fd("Error\n", 2);
	else if (ft_sorted((*a), (*b)))
		ft_putstr_fd("OK\n", 0);
	else
		ft_putstr_fd("KO\n", 0);
}

int	get_cmd(t_push_swap **a, t_push_swap **b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		return (sa(a), 1);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		return (sb(b), 1);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		return (ss(a, b), 1);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		return (pa(b, a), 1);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		return (pb(a, b), 1);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		return (ra(a), 1);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		return (rb(b), 1);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		return (rra(a), 1);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		return (rrb(b), 1);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		return (rrr(a, b), 1);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		return (rrr(a, b), 1);
	else
		return (-1);
}
