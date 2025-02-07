/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:45:28 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/23 11:45:30 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Desplaza hacia abajo todos los elementos del stack b una posición,
//de forma que el último elemento se convierte en el primero.
void	rrb(t_stack *b)
{
	t_node	*primero;
	t_node	*ultimo;

	if (!b->top || b->top == b->bottom)
		return ;
	ultimo = b->bottom;
	primero = b->top;
	b->bottom = ultimo->prev;
	b->bottom->next = NULL;
	ultimo->prev = NULL;
	ultimo->next = primero;
	b->top->prev = ultimo;
	b->top = ultimo;
	write(1, "rrb\n", 4);
}
