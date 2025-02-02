/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:11:15 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/16 21:13:59 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_value_and_index(t_stack *stack_b, int *mvalue, int *mindex)
{
	t_stack	*curr;
	int		i;

	curr = stack_b;
	*mvalue = curr->value;
	*mindex = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > *mvalue)
		{
			*mvalue = curr->value;
			*mindex = i;
		}
		curr = curr->next;
		i++;
	}
}

void	rotate_to_max(t_stack **stack_b, int max_index, int size)
{
	if (max_index < size / 2)
	{
		while (max_index > 0)
		{
			rb(stack_b);
			max_index--;
		}
	}
	else
	{
		max_index = size - max_index;
		while (max_index > 0)
		{
			rrb(stack_b);
			max_index--;
		}
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_value;
	int	max_index;
	int	size;

	while (*stack_b)
	{
		find_max_value_and_index(*stack_b, &max_value, &max_index);
		size = stack_len(*stack_b);
		rotate_to_max(stack_b, max_index, size);
		pa(stack_a, stack_b);
	}
}
