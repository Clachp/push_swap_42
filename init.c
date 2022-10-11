/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:47:42 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 17:57:29 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**get_stack_a(char **argv)
{
	int		i;
	int		n;
	t_stack	**stack_a;
	t_stack	*next_a;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	n = ft_atoi_long(*(argv + 1));
	*stack_a = ft_lstnew(n);
	if (!*stack_a)
		return (NULL);
	i = 2;
	while (*(argv + i))
	{
		n = ft_atoi_long(*(argv + i));
		next_a = ft_lstnew(n);
		if (!next_a)
			return (free(stack_a), NULL);
		lst_add_back(stack_a, next_a);
		i++;
	}
	return (stack_a);
}

void	index_stack(t_stack **a)
{
	t_stack	*first;
	t_stack	*next;

	first = *a;
	while (first)
	{
		next = first->next;
		while (next)
		{
			next->pos++;
			if (first->value < next->value)
				next->index++;
			else
				first->index++;
			next = next->next;
		}
		first = first->next;
	}
}

t_stack	**init_stack_a(char **argv)
{
	t_stack	**stack_a;
	t_stack	*stock;

	stack_a = get_stack_a(argv);
	if (!*stack_a)
	{
		free(stack_a);
		ft_printf("Error\nEmpty stack\n");
		exit(EXIT_FAILURE);
	}
	stock = *stack_a;
	if (is_double(&stock) == 1 || is_sorted(&stock) == 1)
	{
		clear_stack(stack_a);
		free(stack_a);
		exit(EXIT_FAILURE);
	}
	index_stack(stack_a);
	return (stack_a);
}

t_stack	**init_stack_b(void)
{
	t_stack	**stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	*stack_b = NULL;
	return (stack_b);
}
