/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:48:19 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/25 17:48:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_no_empty(t_stack *a, t_stack *b)
{
	int	min_val;

	if (b->size != 0)
	{
		push_back(b, a);
		min_val = get_smallest(a);
		bring_to_top(a, min_val);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3)
		push_cheapest(a, b);
	sort_three(a);
	b_no_empty(a, b);
	return ;
}

void	sort_two(t_stack *a)
{
	t_node	*primero;
	t_node	*segundo;

	if (!a)
		return ;
	primero = a->top;
	segundo = primero->next;
	if (!primero || !segundo)
		return ;
	if (primero->val > segundo->val)
		sa(a);
}

static void	handle_first_is_bigger(t_stack *a)
{
	if (a->top->next->val < a->top->next->next->val)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_three(t_stack *a)
{
	t_node	*primero;
	t_node	*segundo;
	t_node	*tercero;

	if (!a)
		return ;
	primero = a->top;
	segundo = primero->next;
	tercero = segundo->next;
	if (!primero || !segundo || !tercero)
		return ;
	if (primero->val < segundo->val && segundo->val < tercero->val)
		return ;
	if (primero->val > segundo->val && segundo->val < tercero->val
		&& primero->val < tercero->val)
		sa(a);
	else if (primero->val > segundo->val && primero->val > tercero->val)
		handle_first_is_bigger(a);
	else if (primero->val < segundo->val && primero->val > tercero->val)
		rra(a);
	else if (primero->val < segundo->val && segundo->val > tercero->val)
	{
		sa(a);
		ra(a);
	}
}
