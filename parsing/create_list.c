/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:19:57 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/29 18:10:33 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_push_swap	*stack_new(int n)
{
	t_push_swap	*new;

	new = malloc(sizeof(t_push_swap));
	if (!new)
		return (NULL);
	new->content = n;
	new->next = NULL;
	return (new);
}

t_push_swap	*add_content(t_push_swap *s_list, int n)
{
	s_list->content = n;
	return (s_list);
}

void	lst_clear(t_push_swap *lst)
{
	if (lst->next)
		(lst_clear(lst->next));
	free(lst);
}

void	lstadd_front(t_push_swap **lst, t_push_swap *new)
{
	if (!new)
		return (lst_clear(*lst));
	new->next = *lst;
	*lst = new;
}

t_push_swap	*create_stack(char **pstr, int start)
{
	t_push_swap	*a;
	long int	i;
	int			len;

	len = ft_length_tab(pstr, start);
	i = ft_atol_modified(pstr[len - 1 + start]);
	if (i < -2147483648 || i > 2147483647)
		return (NULL);
	a = stack_new((int) i);
	if (!a)
		return (NULL);
	--len;
	while (len + start > start)
	{
		i = ft_atol_modified(pstr[len + start - 1]);
		if (i < -2147483648 || i > 2147483647)
			return (lst_clear(a), NULL);
		lstadd_front(&a, stack_new((int) i));
		if (!a)
			return (NULL);
		--len;
	}
	return (a);
}
