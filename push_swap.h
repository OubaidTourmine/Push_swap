/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:58:51 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/21 19:41:07 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_pos
{
	int				start;
	int				offset;
	int				size;
	int				value;
	int				pos;
}					t_pos;

int					ft_strcmp(char *s1, char *s2);
void				pars_bonus(int ac, char **av, t_stack **stack_a);
int					ft_is_sorted(t_stack *stack);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_is_empty(t_stack *stack);
int					ft_strcheck(char *line, char *str1);
int					ft_check_actions(char *line, t_stack **stack_a,
						t_stack **stack_b);
