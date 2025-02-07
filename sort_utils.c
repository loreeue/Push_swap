/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:29:55 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/25 18:29:57 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *b, t_stack *a)
{
	t_node	*actual;
	int		target;

	actual = b->top;
	while (actual)
	{
		if (b->top == NULL)
			break ;
		actual = b->top;
		target = get_immediate_upper(a, actual->val);
		if (target == INT_MAX)
			target = get_smallest(a);
		else if (target == INT_MIN)
			target = get_smallest(a);
		bring_to_top(a, target);
		pa(a, b);
		actual = actual->next;
	}
}

void	bring_to_top(t_stack *a, int target)
{
	int	depth;

	depth = get_depth(a, target);
	while (depth > 0)
	{
		ra(a);
		depth--;
	}
	while (depth < 0)
	{
		rra(a);
		depth++;
	}
}

int	get_depth(t_stack *from, int n)
{
	int		i;
	t_node	*actual;

	if (!from || !from->top)
		return (INT_MIN);
	i = 0;
	actual = from->top;
	while (actual)
	{
		if (actual->val == n)
		{
			if (i <= from->size / 2)
				return (i);
			else
				return (i - from->size);
		}
		i++;
		actual = actual->next;
	}
	return (INT_MIN);
}
