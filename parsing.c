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

