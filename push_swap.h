/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:48:11 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 17:01:28 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;	
}	t_stack;

/* LST UTILS */
t_stack		*ft_lstnew(int value);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
void		lst_add_back(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst, void (*del)(int));

/* PARSING */
int			is_number(char **argv);
int			is_double(t_stack **stack);
int			is_sorted(t_stack **stack);
long int	ft_atoi_long(const char *nptr);

/* INIT */
t_stack		**init_stack_a(char **argv);
t_stack		**init_stack_b(void);
void		clear(t_stack **a, t_stack **b);
void		clear_stack(t_stack **stack);

/* MOVES UTILS */
void		swap(int *x, int *y);
void		swap_elem(t_stack **stack);
void		push_top_on_top(t_stack **pull, t_stack **push);
void		top_to_bottom(t_stack **stack);
void		bottom_to_top(t_stack **stack);

/* MOVES */
void		push_in_stack(t_stack **a, t_stack **b, char c);
void		swap_stack(t_stack **a, t_stack **b, char c);
void		swap_both_stacks(t_stack **a, t_stack **b);
void		rotate(t_stack **a, t_stack **b, char c);
void		reverse_rotate(t_stack **a, t_stack **b, char c);

/* POSITIONS */
void		get_pos(t_stack **stack);
void		get_target_pos(t_stack **a, t_stack **b);

/* COST */
void		get_cost_a(t_stack **a, t_stack **b);
void		get_cost_b(t_stack **b);
int			get_cost(t_stack *s);
t_stack		*lowest_cost(t_stack **a, t_stack **b);

/* SORT UTILS */
int			get_med(t_stack **a);
t_stack		*get_min(t_stack **stack);
t_stack		*get_max(t_stack **stack);
void		up_number(t_stack **a, t_stack **b, int pos);
void		sort_three(t_stack **a, t_stack **b);

/* SORT */
void		sort_five(t_stack **a, t_stack **b);
void		rough_sort(t_stack **a, t_stack **b);
void		big_sort(t_stack **a, t_stack **b);

#endif
