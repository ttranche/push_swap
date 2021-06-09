/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:32:00 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 18:53:29 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				keep;
	struct s_list	*next;
	struct s_list	*next_sort;
}					t_list;

typedef struct s_mem
{
	t_list			*a;
	t_list			*b;
	int				max;
	int				big;
	int				size;
	int				group_cnt;
	int				group_sz;
	int				print;
	t_list			*temp;
	int				action_count;
}					t_mem;

/*
	Actions
*/
void	swap_a(t_mem *mem);
void	swap_b(t_mem *mem);
void	swap_b_a(t_mem *mem);
void	push_b(t_mem *mem);
void	push_a(t_mem *mem);
void	rev_rotate_a(t_mem *mem);
void	rev_rotate_b(t_mem *mem);
void	rev_rotate_b_a(t_mem *mem);
void	rotate_a(t_mem *mem);
void	rotate_b(t_mem *mem);
void	rotate_b_a(t_mem *mem);
/*
	Utils
*/
int		ft_isdigit(int c);
int		ft_atoi(char *str, t_mem *mem);
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap_list(t_list **prevnext, t_list *last);
void	ft_list_sort(t_list **begin_list);
void	ft_putstr(char *str);
void	ft_puterr(char *str);
void	ft_free_list(t_list **list);
int		list_size(t_list *l);
t_list	*get_last(t_list *l);
int		list_contains_value(t_list *l, int value);
int		is_ordered(t_mem *m);
/*
	Args
*/
void	read_args(int argc, char **argv, t_mem *mem);
/*
	Clean
*/
void	clear_all(t_mem *mem);
void	exit_error(t_mem *mem);
/*
	Stack
*/
void	push_init(t_list **stack, int value, int tag, t_mem *mem);
void	swap_private(t_list **stack);
void	push_top_x1_on_x2(t_list **x1, t_list **x2);
void	put_top_to_bottom(t_list **x);
void	put_bottom_to_top(t_list **x);

#endif
