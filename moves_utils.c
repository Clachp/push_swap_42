/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:05:31 by cchapon           #+#    #+#             */
/*   Updated: 2022/09/26 11:08:56 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elem(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push_top_on_top(t_stack **pull, t_stack **push)
{
	t_stack	*top;

	if (!*pull)
		return ;
	top = *pull;
	*pull = top->next;
	if (*push)
		top->next = (*push);
	else
		top->next = NULL;
	*push = top;
}

void	top_to_bottom(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (!*stack)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	tmp = ft_lstlast(*stack);
	tmp->next = top;
	top->next = NULL;
}

void	bottom_to_top(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	top = *stack;
	*stack = ft_lstlast(*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	(*stack)->next = top;
	tmp->next = NULL;
}
