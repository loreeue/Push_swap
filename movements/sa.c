/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:55:48 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/19 16:55:50 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Intercambia los dos primeros elementos del stack a.
//No hace nada si hay uno o menos elementos.
void	sa(t_stack *a)
{
	t_node	*primero;
	t_node	*segundo;

	if (!a->top || a->top == a->bottom)
		return ;
	primero = a->top;
	segundo = a->top->next;
	primero->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primero;
	segundo->prev = NULL;
	segundo->next = primero;
	a->top = segundo;
	primero->prev = segundo;
	write(1, "sa\n", 3);
}
