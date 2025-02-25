/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:44:08 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/20 21:07:12 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	if (ft_is_empty(stack) == 1)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
		{
			stack = stack->next;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
