/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:02:23 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/20 16:52:03 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	first_b = *stack_b;
	*stack_b = first_b->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	if (stack_a != NULL)
	{
		first_b->next = *stack_a;
		if (*stack_a != NULL)
			(*stack_a)->prev = first_b;
		*stack_a = first_b;
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*first_a;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	if (stack_b != NULL)
	{
		first_a->next = *stack_b;
		if (*stack_b != NULL)
			(*stack_b)->prev = first_a;
		*stack_b = first_a;
	}
}
