/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2large_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:04:10 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/22 16:29:38 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(t_stack **stack_a, int len)
{
	int		*arr;
	int		i;
	t_stack	*curr;

	curr = *stack_a;
	i = 0;
	arr = malloc(sizeof(int) * len);
	while (len > 0)
	{
		arr[i] = curr->value;
		curr = curr->next;
		len--;
		i++;
	}
	i = 0;
	return (arr);
}

int	*sorted_bubble(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
