/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:11:54 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/17 14:31:00 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR "Erreur"
# include "libft.h"

typedef struct t_push_swap
{
	int						content;
	struct t_push_swap		*next;
}	t_push_swap;

t_push_swap	*stack_new(int n);
t_push_swap	*add_content(t_push_swap *s_list, int n);
void		lstadd_front(t_push_swap **lst, t_push_swap *new);
int			ft_str_isdigit(char *s);
void		lst_clear(t_push_swap *lst);
int			check_table_is_int(char **table, int start);
t_push_swap	*wich_parsing(int argc, char *argv[]);
t_push_swap	*parse_with_split(char *str);
t_push_swap	*parse_for_args(char **argv);
t_push_swap	*create_stack(char **pstr, int start);
void		deploy_table(t_push_swap **a);
long int	ft_atol_modified(char *s);
void		free_table_char(char **pptr);
int			check_untl_lst(t_push_swap *a, int dob);
int			check_doble_lst(t_push_swap *a);
int			ft_length_tab(char **pstr, int start);

#endif