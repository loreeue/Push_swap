/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:30:08 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/25 17:30:43 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node	*actual;
	t_node	*temp;

	actual = a->top;
	while (actual != NULL)
	{
		temp = actual->next;
		free(actual);
		actual = temp;
	}
	free(a);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_frees_two_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
