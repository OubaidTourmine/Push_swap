/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:40:39 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/26 21:43:55 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_numbers(char **av)
{
	int		i;
	int		j;
	char	**numbers;
	int		num_count;

	num_count = 0;
	i = 0;
	while (av[i])
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j])
		{
			num_count++;
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
	return (num_count);
}

int	check_duplicate(int *stored_nums, int current_number, int num_count)
{
	int	k;

	k = 0;
	while (k < num_count)
	{
		if (stored_nums[k] == current_number)
		{
			return (0);
		}
		k++;
	}
	return (1);
}

int	process_argument(char *arg, int *stored_nums, int *num_count)
{
	char	**numbers;
	int		j;
	int		current_number;

	numbers = ft_split(arg, ' ');
	j = 0;
	while (numbers[j])
	{
		if (!ft_isdigit(numbers[j]))
		{
			error_and_free(numbers, stored_nums);
		}
		current_number = ft_atoi(numbers[j], numbers, stored_nums);
		if (!(check_duplicate(stored_nums, current_number, *num_count)))
		{
			error_and_free(numbers, stored_nums);
		}
		stored_nums[*num_count] = current_number;
		(*num_count)++;
		j++;
	}
	ft_free(numbers);
	return (j);
}

void	store_numbers(char **av, int *stored_nums)
{
	int	i;
	int	j;
