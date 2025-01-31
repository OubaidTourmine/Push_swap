/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1large_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:14:26 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/16 22:46:39 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	large(t_stack **stack_a, t_stack **stack_b)
{
	int	offset;

	offset = cal_offset(*stack_a);
	push_to_b(stack_a, stack_b, offset);
	push_to_a(stack_a, stack_b);
}

void	handle_push(t_stack **stack_a, t_stack **stack_b, int index,
		t_pos *params)
{
	if (index < params->start)
	{
		if (params->offset < params->size - 1)
			(params->offset)++;
		if (params->start < params->offset - 1)
			(params->start)++;
		pb(stack_b, stack_a);
	}
	else if (index <= params->offset)
	{
		pb(stack_b, stack_a);
		rb(stack_b);
		if (params->offset < params->size - 1)
			(params->offset)++;
		if (params->start < params->offset - 1)
			(params->start)++;
	}
	else
		ra(stack_a);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int offset)
{
	t_pos	params;
	int		*arr;
	int		size;
	int		index;

	params.start = 0;
	params.offset = offset;
	size = stack_len(*stack_a);
	params.size = size;
	arr = sorted_bubble(sort_arr(stack_a, size), size);
	while (*stack_a)
	{
		index = get_index(arr, (*stack_a)->value, size);
		handle_push(stack_a, stack_b, index, &params);
	}
	free(arr);
}
