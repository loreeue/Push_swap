/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:09:00 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/23 13:09:01 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_obtain_nums(int argc, char *argv[])
{
	char	**nums;

	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = argv + 1;
	return (nums);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = create_stack();
	b = create_stack();
	if (argc == 1)
		return (1);
	if (handle_errors(argc, argv))
	{
		write(1, "Error\n", 6);
		return (ft_frees_two_stacks(a, b), 1);
	}
	args = ft_obtain_nums(argc, argv);
	init_stack_a(a, args);
	if (argc == 2)
		ft_free_split(args);
	if (has_nums_dup(a))
	{
		write(1, "Error\n", 6);
		return (ft_frees_two_stacks(a, b), 1);
	}
	if (!stack_sorted(a))
		sort(a, b);
	return (ft_frees_two_stacks(a, b), 0);
}
