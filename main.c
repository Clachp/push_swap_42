/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:47:26 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/07 12:19:46 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (!stack)
		return ;
	first = *stack;
	while (first != 0)
	{
		temp = first->next;
		free(first);
		first = temp;
	}
	*stack = NULL;
}

void	clear(t_stack **a, t_stack **b)
{
	clear_stack(a);
	clear_stack(b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc > 2)
	{
		if (is_number(argv) == 1)
			exit (EXIT_FAILURE);
		a = init_stack_a(argv);
		b = init_stack_b();
		if (argc <= 4)
			sort_three(a, b);
		else
			big_sort(a, b);
		clear(a, b);
	}
	else
	{
		is_number(argv);
		exit (EXIT_FAILURE);
	}
	return (0);
}
