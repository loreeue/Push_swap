/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:10:18 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/20 15:10:20 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Toma el primer elemento del stack b y lo pone el primero en el stack a.
//No hace nada si b está vacío.
void	pa(t_stack *a, t_stack *b)
{
	t_node	*primero_b;

	if (b->size == 0)
		return ;
	primero_b = b->top;
	b->top = primero_b->next;
	if (b->top != NULL)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	primero_b->next = a->top;
	if (a->top != NULL)
		a->top->prev = primero_b;
	else
		a->bottom = primero_b;
	a->top = primero_b;
	a->top->prev = NULL;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}
