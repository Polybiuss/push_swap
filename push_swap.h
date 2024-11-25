/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:11:54 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/25 19:23:20 by jbergos          ###   ########.fr       */
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

typedef	struct s_chunk
{
	int len;
	int	n;
	int middle;
	int offset;
	int start;
	int end;
	int *tab_sorted;
	int	down;
}	t_chunck;

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
int			ft_reverse_sort_one_lst(t_push_swap **one);
int			ft_sort_one_lst(t_push_swap **one);
t_chunck	*create_chunk(t_push_swap **a);
void		find_start(t_push_swap **a, t_chunck *chunk);
void		find_end(t_push_swap **a, t_chunck *chunk);
void		find_start_and_end(t_push_swap **a, t_chunck *chunk);
int			new_start(t_chunck *chunk);
int			new_end(t_chunck *chunk);
int			wish_n(int len);
int			find_middle(int *tab, int len);
void		ft_swap(int *a, int *b);
void		ft_sort_int_tab(int *tab, int size);
int			middle_lst(t_push_swap **a, int len);
int			*tab_sorted(t_push_swap **a, int len);
void		check_b_chunk(t_push_swap **b, t_chunck *chunk);
void		push_b_chunk(t_push_swap **a, t_push_swap **b, int in, t_chunck *c);
int			find_chunk_numb(t_push_swap **a, t_chunck *chunk);
void		push_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk);
int			is_rotate_b(t_push_swap **b, t_chunck *chunk);
int			find_chunk_numb_b(t_push_swap **b, int find);
int			find_rchunk_numb_b(t_push_swap **b, int find);
void		push_sorted_chunk(t_push_swap **a, t_push_swap **b, t_chunck *chunk);
void		push_to_queue(t_push_swap **a, t_push_swap **b, t_chunck *chunk);
void		to_aa(t_push_swap **a, t_push_swap **b, int index, t_chunck *chunk);
void		chuck_down(t_push_swap **a, t_chunck *chunk);
void		to_ra(t_push_swap **a, t_push_swap**b, int index);
int			last_value(t_push_swap **a);

#endif