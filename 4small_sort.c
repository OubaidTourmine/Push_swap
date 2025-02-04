/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4small_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:19 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/18 16:38:07 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	num_count;

	num_count = stack_len(*stack_a);
	if (num_count == 1)
		return ;
	else if (num_count == 2)
		two(stack_a);
	else if (num_count == 3)
		three(stack_a);
	else if (num_count <= 10)
		ten(stack_a, stack_b);
	else
		large(stack_a, stack_b);
}

void	two(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack_a;
	tail = head->next;
	if (head->value > tail->value)
		sa(stack_a);
	else
		return ;
}

void	three(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*mid;
	t_stack	*tail;

	head = *stack_a;
	mid = head->next;
	tail = mid->next;
	if (tail->value > mid->value && mid->value > head->value)
		return ;
	else if (tail->value > head->value && head->value > mid->value)
