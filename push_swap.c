/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:34:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/13 22:40:39 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	checker_arg(int argc)
// {
// 	if (argc == 1)
// 		return (0);
// 	if (argc == 2)
// 		return (1);
// 	else
// 		return (2);
// }
void	free_table_char(char **pptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(pptr[i]);
		++i;
	}
	free(pptr);
}
// int	*convert_table_char_to_int(char **table_char, int (*f)(const char *nptr))
// {
// 	size_t	i;
// 	int		*table;

// 	i = 0;
// 	while (table_char[i])
// 		++i;
// 	table = malloc(sizeof(int *) * (i + 1));
// 	if (!table)
// 		return (NULL);
// 	i = 0;
// 	while (table_char[i])
// 	{
// 		table[i] = f(table_char[i]);
// 		++i;
// 	}
// 	table[i] = 0;
// 	free_table_char(table_char, i);
// 	return (table);
// }
int	check_table_is_int(char **table)
{
	size_t	i;

	i = 0;
	while (table[i])
	{
		if (table[i][0] == '+' || table[i][0] == '-')
		{
			if (!ft_isdigit((table[i] + 1)))
				return (0);
			if (ft_strlen(table[i] > 12))
				return (0);
		}
		else
		{
			if (!ft_isdigit((table[i])))
				return (0);
			if (ft_strlen(table[i] > 12))
				return (0);
		}
			
	}
}
int	*parse_with_split(char *str)
{
	char	**table_char;
	table_char = ft_split(str, ' ');
	if (check_table_is_int(table_char))
		return (NULL);
	
	// return (convert_table_char_to_int(table_char, &ft_atoi));
}

int	*wich_parsing(int argc, char *argv[])
{
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		return (parse_with_split(argv[1])); //split & atoi
	else // argc > 2
		return (NULL); // no split only atoi
}
void	deploy_table(int *table)
{
	size_t	i;

	i = 0;
	while (table[i])
	{
		ft_putstr_fd(ft_itoa(table[i]), 0);
		++i;
	}
}
int	main(int argc, char *argv[])
{
	int	*table;
	table = wich_parsing(argc, argv);
	table ? deploy_table(table) : ft_putstr_fd("Error", 0);
	return (0);
}
