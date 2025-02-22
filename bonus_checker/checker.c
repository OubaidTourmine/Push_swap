/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:44:35 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/26 21:51:21 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "checker.h"

int	ft_check_actions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_b, stack_a);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	ft_helper(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			return (1);
		}
		if (ft_check_actions(line, stack_a, stack_b))
			free(line);
		else
		{
			free(line);
			return (0);
		}
	}
}

void	pars_bonus(int ac, char **av, t_stack **stack_a)
{
	int	*stored_nums;
	int	num_count;

	ac--;
	av++;
	num_count = count_total_numbers(av);
	stored_nums = malloc(sizeof(int) * num_count);
	if (!stored_nums)
		exit(0);
	store_numbers(av, stored_nums);
	while (0 < num_count)
	{
		push_stack(stored_nums[num_count - 1], stack_a);
		num_count--;
	}
	free(stored_nums);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(1);
	pars_bonus(ac, av, &stack_a);
	if (ft_helper(&stack_a, &stack_b))
	{
		if (ft_is_sorted(stack_a) == 1 && ft_is_empty(stack_b) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
