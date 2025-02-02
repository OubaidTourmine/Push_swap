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
