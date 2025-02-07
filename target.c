/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:11:12 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/26 18:11:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stack *stack, int n, int bol)
{
	if (is_biggest(stack, n) || is_smallest(stack, n))
		return (get_biggest(stack));
	else if (bol)
		return (get_immediate_lower(stack, n));
	else if (!bol)
		return (get_immediate_upper(stack, n));
	else
		return (INT_MIN);
}

//Busca el elemento inmediatamente menor a n en la pila to_search
int	get_immediate_lower(t_stack *stack, int n)
{
	int		dif;
	int		target;
	t_node	*curr;

	if (!stack->top)
		return (INT_MIN);
	dif = INT_MAX;
	target = INT_MIN;
	curr = stack->top;
	while (curr != NULL)
	{
		if (n - curr->val < dif && n - curr->val > 0)
		{
			dif = n - curr->val;
			target = curr->val;
		}
		curr = curr->next;
	}
	return (target);
}

//Busca el elemento inmediatamente mayor a n en la pila to_search
int	get_immediate_upper(t_stack *stack, int target)
{
	t_node	*current;
	int		closest_val;
	int		closest_diff;
	int		diff;

	if (!stack || !stack->top)
		return (INT_MIN);
	current = stack->top;
	closest_val = INT_MIN;
	closest_diff = INT_MAX;
	if (is_biggest(stack, target))
		return (INT_MAX);
	while (current != NULL)
	{
		diff = current->val - target;
		if (diff > 0 && diff < closest_diff)
		{
			closest_diff = diff;
			closest_val = current->val;
		}
		current = current->next;
	}
	return (closest_val);
}
