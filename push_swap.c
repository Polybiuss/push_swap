/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/25 18:53:02 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_push_swap	*a;
	t_push_swap *b = NULL;

	if (argc == 1)
		return (0);
	a = wich_parsing(argc, argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 0), 3);
	if (!check_doble_lst(a))
	{
		lst_clear(a);
		return (ft_putstr_fd("Error\n", 0), 3);
	}
	if (ft_sorted(a, b))
		return (0);
	else
		// testing_cmd(&a, &b);
		ft_sort(&a, &b);
	if (a)
		lst_clear(a);
	if (b)
		lst_clear(b);
	return (0);
}
