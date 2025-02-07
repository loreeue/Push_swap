/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:18:24 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/26 19:18:26 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sincroniza los movimientos de las dos pilas al mover elementos en la misma
//dirección, utilizando rotaciones dobles (rr para arriba o rrr para abajo).
//Ajusta las profundidades (a_depth y b_depth) hasta que ya no coincidan en
//dirección
static void	synchronize_rotations(t_stack *a, t_stack *b, int *a_depth,
	int *b_depth)
{
	while (*a_depth != 0 && *b_depth != 0)
	{
		if (*a_depth > 0 && *b_depth > 0)
		{
			rr(a, b);
			(*a_depth)--;
			(*b_depth)--;
		}
		else if (*a_depth < 0 && *b_depth < 0)
		{
			rrr(a, b);
			(*a_depth)++;
			(*b_depth)++;
		}
		else
			break ;
	}
}

//Encuentra y mueve el valor más "barato" de la pila a a la posición correcta
//en la pila b.
//Calcula las profundidades necesarias, sincroniza movimientos con aux_cheapest,
//realiza las rotaciones restantes en ambas pilas, y finalmente realiza un pb
//para empujar el valor a b
void	push_cheapest(t_stack *a, t_stack *b)
{
	int	val_cheapest;
	int	a_depth;
	int	b_depth;

	val_cheapest = get_cheapest(a, b);
	a_depth = get_depth(a, val_cheapest);
	b_depth = get_depth(b, get_target(b, val_cheapest, 1));
	synchronize_rotations(a, b, &a_depth, &b_depth);
	while (a_depth > 0 && a_depth--)
		ra(a);
	while (a_depth < 0 && a_depth++)
		rra(a);
	while (b_depth > 0 && b_depth--)
		rb(b);
	while (b_depth < 0 && b_depth++)
		rrb(b);
	pb(a, b);
}
