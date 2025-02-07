/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:35:01 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/23 10:35:03 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Desplaza hacia arriba todos los elementos del stack a una posición,
//de forma que el primer elemento se convierte en el último.
void	ra(t_stack *a)
{
	t_node	*primero;
	t_node	*segundo;
	t_node	*ultimo;

	if (!a->top || a->top == a->bottom)
		return ;
	primero = a->top;
	segundo = primero->next;
	ultimo = a->bottom;
	a->top = segundo;
	a->top->prev = NULL;
	ultimo->next = primero;
	a->bottom = primero;
	primero->next = NULL;
	primero->prev = ultimo;
	write(1, "ra\n", 3);
}
