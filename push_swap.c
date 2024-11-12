/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/12 23:41:58 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_arg(int argc)
{
	if (argc == 1)
		ft_putstr_fd("1", 0);
	if (argc == 2)
		ft_putstr_fd("2", 0);
	else
		ft_putstr_fd("2 et plus", 0);
}

int	main(int argc, char *argv[])
{
	checker_arg(argc);
	return (0);
}
