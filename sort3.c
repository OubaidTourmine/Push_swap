/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:06:03 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/18 16:01:38 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
