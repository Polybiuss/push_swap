/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:11:54 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/19 14:08:41 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// # define ERROR "Error\n
# include "libft.h"
# include <stdio.h>

typedef struct s_push_swap
{
	int						content;
	struct s_push_swap		*next;
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
long int	ft_atol_modified(char *s);
void		free_table_char(char **pptr);
int			check_untl_lst(t_push_swap *a, int dob);
int			check_doble_lst(t_push_swap *a);
int			ft_length_tab(char **pstr, int start);
void		swap_a(t_push_swap **a, int bl);
void		swap_b(t_push_swap **b, int bl);
void		swap_s(t_push_swap **a, t_push_swap **b);
void		push_a(t_push_swap **b, t_push_swap **a);
void		push_b(t_push_swap **a, t_push_swap **b);
void		rotate_a(t_push_swap **a, int bl);
void		rotate_b(t_push_swap **b, int bl);
void		rotate_rr(t_push_swap **a, t_push_swap **b);
void		reverse_rotate_a(t_push_swap **a, int bl);
void		reverse_rotate_r(t_push_swap **a, t_push_swap **b);
void		reverse_rotate_b(t_push_swap **b, int bl);
void		testing_cmd(t_push_swap **a, t_push_swap **b);
void		deploy_all_table(t_push_swap *a, t_push_swap *b);
void		testing_cmd(t_push_swap **a, t_push_swap **b);
int			length_lst(t_push_swap **a);
int			somme_lst(t_push_swap **a);
int			ft_sorted(t_push_swap *a, t_push_swap *b);
int			median_lst(t_push_swap **a);
void		ft_sort(t_push_swap **a, t_push_swap **b);
void		sort_two(t_push_swap **a);
int			ft_reverse_sort_one_lst(t_push_swap **one);
int			ft_sort_one_lst(t_push_swap **one);

#endif