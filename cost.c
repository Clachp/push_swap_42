/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:56:53 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 15:17:38 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost_a(t_stack **a, t_stack **b)
{
	int		mid;
	int		i;
	t_stack	*tmp;

	if (!a || !b)
		return ;
	mid = ft_lstsize(*a) / 2;
	tmp = *b;
	while (tmp)
	{
		tmp->cost_a = 0;
		i = tmp->target_pos;
		if (tmp->target_pos <= mid)
			tmp->cost_a = tmp->target_pos;
		else
		{
			while (i++ < ft_lstsize(*a))
				tmp->cost_a--;
		}	
		tmp = tmp->next;
	}
}

void	get_cost_b(t_stack **b)
{
	int		mid;
	int		i;
	t_stack	*tmp;

	if (!b)
		return ;
	mid = ft_lstsize(*b) / 2;
	tmp = *b;
	while (tmp)
	{
		tmp->cost_b = 0;
		i = tmp->pos;
		if (tmp->pos <= mid)
			tmp->cost_b = tmp->pos;
		else
		{
			while (i++ < ft_lstsize(*b))
				tmp->cost_b--;
		}
		tmp = tmp->next;
	}
}

int	get_cost(t_stack *s)
{
	int	cost_a;
	int	cost_b;

	cost_a = s->cost_a;
	cost_b = s->cost_b;
	if (s->cost_a < 0)
		cost_a *= -1;
	if (s->cost_b < 0)
		cost_b *= -1;
	return (cost_a + cost_b);
}

t_stack	*lowest_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*to_sort;
	int		cheap_cost;
	int		tmp_cost;

	if (!a || !b)
		return (NULL);
	get_cost_a(a, b);
	get_cost_b(b);
	to_sort = *b;
	tmp = (*b)->next;
	while (tmp)
	{
		cheap_cost = get_cost(to_sort);
		tmp_cost = get_cost(tmp);
		if (tmp_cost < cheap_cost)
			to_sort = tmp;
		tmp = tmp->next;
	}
	return (to_sort);
}
