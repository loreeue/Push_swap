/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:09 by loruzqui          #+#    #+#             */
/*   Updated: 2024/12/11 15:50:01 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

static t_node	*create_node(long num, t_node *prev_node)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->val = num;
	new_node->next = NULL;
	new_node->prev = prev_node;
	if (prev_node)
		prev_node->next = new_node;
	return (new_node);
}

void	init_stack_a(t_stack *a, char **s)
{
	int		i;
	long	num;
	t_node	*prev_node;
	t_node	*new_node;

	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	prev_node = NULL;
	i = 0;
	while (s[i] != NULL)
	{
		num = ft_atol(s[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free_stack(a));
		new_node = create_node(num, prev_node);
		if (!new_node)
			return (free_stack(a));
		if (!a->top)
			a->top = new_node;
		prev_node = new_node;
		a->size++;
		i++;
	}
	a->bottom = prev_node;
}
