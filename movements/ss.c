/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:06:24 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/20 15:06:26 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap a y swap b a la vez.
void	ss(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;

	if (!a->top || a->top == a->bottom)
		return ;
	node_a = a->top;
	node_a->next = a->top->next->next;
	if (a->top->next->next)
		a->top->next->next->prev = node_a;
	a->top->next->prev = NULL;
	a->top->next->next = node_a;
	a->top = a->top->next;
	node_a->prev = a->top->next;
	if (!b->top || b->top == b->bottom)
		return ;
	node_b = b->top;
	node_b->next = b->top->next->next;
	if (b->top->next->next)
		b->top->next->next->prev = node_b;
	b->top->next->prev = NULL;
	b->top->next->next = node_b;
	b->top = b->top->next;
	node_b->prev = b->top->next;
	write(1, "ss\n", 3);
}
