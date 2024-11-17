/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/17 14:36:39 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_push_swap	*table;

	if (argc == 1)
		return (0);
	table = wich_parsing(argc, argv);
	if (!table)
		return (ft_putstr_fd(ERROR, 0), 0);
	if (!check_doble_lst(table))
	{
		lst_clear(table);
		return (ft_putstr_fd(ERROR, 0), 0);
	}
	deploy_table(&table);
	lst_clear(table);
	return (0);
}
