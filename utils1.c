/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:35:38 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/17 15:34:29 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_stack(int value, t_stack **stack_a)
{
	t_stack	*node;

	node = create_stack(value);
	node->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = node;
	node->prev = NULL;
	*stack_a = node;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

t_pos	*minimum_value(t_stack *stack_x)
{
	t_pos	*pos;
	int		i;

	i = 0;
	pos = malloc(sizeof(t_pos));
	pos->value = stack_x->value;
	pos->pos = i;
	while (stack_x)
	{
		if (stack_x->value < pos->value)
		{
			pos->value = stack_x->value;
			pos->pos = i;
		}
		stack_x = stack_x->next;
		i++;
	}
	return (pos);
}

// void	ft_print_stack(t_stack *stack)
// {
// 	if (!stack)
// 		return ;
// 	printf("%d\n", stack->value);
// 	ft_print_stack(stack->next);
// }
