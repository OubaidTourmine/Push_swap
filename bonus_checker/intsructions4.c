/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:06:03 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/20 16:52:18 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
