/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:22:24 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/20 15:22:25 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Toma el primer elemento del stack a y lo pone el primero en el stack b.
//No hace nada si a está vacío.
void	pb(t_stack *a, t_stack *b)
{
	t_node	*primero_a;

	if (a->size == 0)
		return ;
	primero_a = a->top;
	a->top = primero_a->next;
	if (a->top != NULL)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	primero_a->next = b->top;
	if (b->top != NULL)
		b->top->prev = primero_a;
	else
		b->bottom = primero_a;
	b->top = primero_a;
	b->top->prev = NULL;
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}
