/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:04:45 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/20 15:04:47 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Intercambia los dos primeros elementos del stack b.
//No hace nada si hay uno o menos elementos.
void	sb(t_stack *b)
{
	t_node	*primero;
	t_node	*segundo;

	if (!b->top || b->top == b->bottom)
		return ;
	primero = b->top;
	segundo = b->top->next;
	primero->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primero;
	segundo->prev = NULL;
	segundo->next = primero;
	b->top = segundo;
	primero->prev = segundo;
	write(1, "sb\n", 3);
}
