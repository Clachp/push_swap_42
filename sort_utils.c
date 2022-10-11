/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:54:20 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 17:27:25 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_med(t_stack **a)
{
	int	m;
	int	n;

	n = ft_lstsize(*a);
	if (n % 2 != 0)
		m = (n + 1) / 2;
	else
		m = n / 2;
	return (m);
}

t_stack	*get_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = (*stack)->next;
	min = *stack;
	while (tmp)
	{
		if (min->index > tmp->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*get_max(t_stack **stack)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = (*stack)->next;
	max = *stack;
	while (tmp)
	{
		if (max->index < tmp->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	up_number(t_stack **a, t_stack **b, int pos)
{
	if (pos <= (ft_lstsize(*a) / 2))
	{
		while ((*a)->pos != pos)
			rotate(a, b, 'a');
	}
	else
	{
		while ((*a)->pos != pos)
			reverse_rotate(a, b, 'a');
	}
}

void	sort_three(t_stack **a, t_stack **b)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = *a;
	two = (*a)->next;
	three = (*a)->next->next;
	if (ft_lstsize(*a) == 3)
	{
		if (one->index > two->index && one->index > three->index)
			rotate (a, b, 'a');
		else if (two->index > one->index && two->index > three->index)
			reverse_rotate(a, b, 'a');
	}
	if ((*a)->index > (*a)->next->index)
		swap_stack(a, b, 'a');
}
