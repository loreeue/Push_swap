/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:51:44 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/23 10:51:46 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Desplaza hacia arriba todos los elementos del stack b una posición,
//de forma que el primer elemento se convierte en el último.
void	rb(t_stack *b)
{
	t_node	*primero;
	t_node	*segundo;
	t_node	*ultimo;

	if (!b->top || b->top == b->bottom)
		return ;
	primero = b->top;
	segundo = primero->next;
	ultimo = b->bottom;
	b->top = segundo;
	b->top->prev = NULL;
	ultimo->next = primero;
	b->bottom = primero;
	primero->next = NULL;
	primero->prev = ultimo;
	write(1, "rb\n", 3);
}
