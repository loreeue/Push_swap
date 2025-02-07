/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:16:49 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/26 18:16:51 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Determina si n es el número más grande en la pila
int	is_biggest(t_stack *stack, int n)
{
	t_node	*actual;

	if (!stack->top)
		return (INT_MIN);
	actual = stack->top;
	while (actual)
	{
		if (n < actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

//Determina si n es el número más pequeño en la pila
int	is_smallest(t_stack *stack, int n)
{
	t_node	*actual;

	if (!stack->top)
		return (INT_MAX);
	actual = stack->top;
	while (actual)
	{
		if (n > actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

//Devuelve el número más grande de la pila
int	get_biggest(t_stack *stack)
{
	t_node	*actual;
	int		max;

	if (!stack->top)
		return (INT_MIN);
	actual = stack->top;
	max = actual->val;
	while (actual != NULL)
	{
		if (max < actual->val)
			max = actual->val;
		actual = actual->next;
	}
	return (max);
}

//Devuelve el número más pequeño de la pila
int	get_smallest(t_stack *stack)
{
	t_node	*actual;
	int		min;

	if (!stack->top)
		return (INT_MAX);
	actual = stack->top;
	min = actual->val;
	while (actual != NULL)
	{
		if (min > actual->val)
			min = actual->val;
		actual = actual->next;
	}
	return (min);
}
