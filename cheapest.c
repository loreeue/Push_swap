/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:36 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/26 16:41:38 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calcula el número total de movimientos necesarios para alinear dos elementos
//en dos pilas diferentes
static int	num_of_moves(int a_depth, int b_depth)
{
	if ((a_depth > 0 && b_depth > 0) || (a_depth < 0 && b_depth < 0))
		return (max(abs(a_depth), abs(b_depth)));
	return (abs(a_depth) + abs(b_depth));
}

//Calcula el número total de movimientos necesarios para mover
//un valor (val) desde una pila (a) a la posición objetivo en otra pila (b)
static int	get_combined_moves(t_stack *a, t_stack *b, int val)
{
	int	a_depth;
	int	target;
	int	b_depth;

	a_depth = get_depth(a, val);
	target = get_target(b, val, 1);
	b_depth = get_depth(b, target);
	return (num_of_moves(a_depth, b_depth));
}

//Actualiza el valor más barato (cheapest_val) y los movimientos necesarios
//(actual_steps) si el número de movimientos actuales (combined_moves) es
//menor que el registrado anteriormente
static void	update_cheapest(int *actual_steps, int combined_moves,
		int *cheapest_val, int val)
{
	if (combined_moves < *actual_steps)
	{
		*actual_steps = combined_moves;
		*cheapest_val = val;
	}
}

//Encuentra el valor más "barato" en una pila (a) para moverlo a la
//posición correcta en otra pila (b)
int	get_cheapest(t_stack *a, t_stack *b)
{
	t_node	*actual;
	int		actual_steps;
	int		cheapest_val;
	int		combined_moves;

	actual = a->top;
	actual_steps = INT_MAX;
	cheapest_val = INT_MIN;
	while (actual != NULL)
	{
		combined_moves = get_combined_moves(a, b, actual->val);
		update_cheapest(&actual_steps, combined_moves, &cheapest_val,
			actual->val);
		actual = actual->next;
	}
	return (cheapest_val);
}
