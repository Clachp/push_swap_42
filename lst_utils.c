/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:07:34 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 16:18:59 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*first;
	t_stack	*temp;

	if (!lst || !del)
		return ;
	first = *lst;
	while (first != 0)
	{
		del(first->value);
		temp = first->next;
		free(first);
		first = temp;
	}
	*lst = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
