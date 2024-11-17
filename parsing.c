/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:47:23 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/17 12:54:26 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*wich_parsing(int argc, char *argv[])
{
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		return (parse_with_split(argv[1]));
	else
		return (parse_for_args(argv));
}

t_push_swap	*parse_with_split(char *str)
{
	t_push_swap		*stack_a;
	char			**table_char;

	table_char = ft_split(str, ' ');
	if (!table_char)
		return (NULL);
	if (!check_table_is_int(table_char, 0))
		return (free_table_char(table_char), NULL);
	stack_a = create_stack(table_char, 0);
	if (!stack_a)
		return (free_table_char(table_char), NULL);
	return (free_table_char(table_char), stack_a);
}

t_push_swap	*parse_for_args(char **argv)
{
	t_push_swap	*a;

	if (!check_table_is_int(argv, 1))
		return (NULL);
	a = create_stack(argv, 1);
	if (!a)
		return (NULL);
	return (a);
}
