/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:38:24 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 16:49:19 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

int	target_pos(int index, t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target_pos;

	get_pos(a);
	get_pos(b);
	tmp = *a;
	target_pos = 0;
	if (index < get_min(a)->index)
		target_pos = get_min(a)->pos;
	else
	{
		while (tmp->next)
		{
			if (index > tmp->index && index < tmp->next->index)
				target_pos = tmp->pos + 1;
			tmp = tmp->next;
		}
	}
	return (target_pos);
}

void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->target_pos = target_pos(tmp_b->index, a, b);
		tmp_b = tmp_b->next;
	}
	get_cost_a(a, b);
	get_cost_b(b);
}
