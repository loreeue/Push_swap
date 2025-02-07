/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:48:39 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/19 16:48:41 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "limits.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

int		main(int argc, char *argv[]);

//MOVEMENTS
void	sa(t_stack *a);
void	sb(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *a);
void	rrr(t_stack *a, t_stack *b);

//BIG SMALL
int		is_biggest(t_stack *stack, int n);
int		is_smallest(t_stack *stack, int n);
int		get_biggest(t_stack *stack);
int		get_smallest(t_stack *stack);

//CHEAPEST
int		get_cheapest(t_stack *a, t_stack *b);

//FREES
void	free_stack(t_stack *a);
void	ft_free_split(char **split);
void	ft_frees_two_stacks(t_stack *a, t_stack *b);

//HANDLE ERRORS
int		handle_errors(int argc, char *argv[]);
int		has_nums_dup(t_stack *stack);
int		stack_sorted(t_stack *s);

//PUSH CHEAPEST
void	push_cheapest(t_stack *a, t_stack *b);

//SORT UTILS
void	push_back(t_stack *b, t_stack *a);
void	bring_to_top(t_stack *a, int target);
int		get_depth(t_stack *from, int n);

//SORT
void	sort(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);

//TARGET
int		get_target(t_stack *stack, int n, int bol);
int		get_immediate_lower(t_stack *stack, int n);
int		get_immediate_upper(t_stack *stack, int target);

//STACK UTILS
t_stack	*create_stack(void);
void	init_stack_a(t_stack *a, char **s);

//VALIDATE INPUT
int		validate_input(int argc, char **argv);

#endif
