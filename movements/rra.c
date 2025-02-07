/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:54:26 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/23 10:54:28 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Desplaza hacia abajo todos los elementos del stack a una posición,
//de forma que el último elemento se convierte en el primero.
void	rra(t_stack *a)
{
	t_node	*primero;
	t_node	*ultimo;

	if (!a->top || a->top == a->bottom)
		return ;
	primero = a->top;
	ultimo = a->bottom;
	a->bottom = ultimo->prev;
	a->bottom->next = NULL;
	ultimo->prev = NULL;
	ultimo->next = primero;
	a->top->prev = ultimo;
	a->top = ultimo;
	write(1, "rra\n", 4);
}
