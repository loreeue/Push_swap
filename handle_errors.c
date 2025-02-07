/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:28:57 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/25 16:28:59 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_empty_string(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && !(s[i] >= 7 && s[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

static int	is_in_range(char *s)
{
	long	num;
	char	**numbers;
	int		i;

	numbers = ft_split(s, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i] != NULL)
	{
		num = ft_atol(numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_free_split(numbers);
			return (0);
		}
		i++;
	}
	ft_free_split(numbers);
	return (1);
}

int	handle_errors(int argc, char *argv[])
{
	int	i;

	if (argc > 1 && is_empty_string(argv[1]))
		return (1);
	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!is_in_range(argv[i]))
			return (1);
		i++;
	}
	if (!validate_input(argc, argv))
		return (1);
	return (0);
}

int	has_nums_dup(t_stack *stack)
{
	t_node	*ini;
	t_node	*sig;

	ini = stack->top;
	while (ini != NULL)
	{
		sig = ini->next;
		while (sig != NULL)
		{
			if (ini->val == sig->val)
				return (1);
			sig = sig->next;
		}
		ini = ini->next;
	}
	return (0);
}

int	stack_sorted(t_stack *s)
{
	t_node	*n;

	if (!s || !s->top)
		return (1);
	n = s->top;
	while (n && n->next)
	{
		if (n->val > n->next->val)
			return (0);
		n = n->next;
	}
	return (1);
}
