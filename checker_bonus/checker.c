/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:04:38 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:07:36 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	*a;
	t_push_swap	*b;

	b = NULL;
	if (argc == 1)
		return (0);
	a = wich_parsing(argc, argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 3);
	if (!check_doble_lst(a))
	{
		lst_clear(a);
		return (ft_putstr_fd("Error\n", 2), 3);
	}
	get_line(&a, &b);
	if (a)
		lst_clear(a);
	if (b)
		lst_clear(b);
	return (0);
}
