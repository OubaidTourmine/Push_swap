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

