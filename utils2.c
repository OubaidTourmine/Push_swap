/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:38:07 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/21 19:40:03 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr, char **numbers, int *stored_nums)
{
	int		i;
	long	result;
	long	signe;

	i = 0;
	result = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (result * signe > INT_MAX || result * signe < INT_MIN)
		error_and_free(numbers, stored_nums);
	return (result * signe);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	valid(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
		{
			exit(0);
		}
		i++;
	}
	return (1);
}

void	error_and_free(char **numbers, int *stored_nums)
{
	ft_free(numbers);
	free(stored_nums);
	write(2, "Error\n", 6);
	exit(1);
}

int	stack_len(t_stack *a)
{
	int		count;
	t_stack	*curr;

	count = 0;
	curr = a;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
