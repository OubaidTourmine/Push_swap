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
int					ft_helper(t_stack **stack_a, t_stack **stack_b);
void				store_numbers(char **av, int *stored_nums);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					*sort_arr(t_stack **stack_a, int len);
int					*sorted_bubble(int *arr, int len);
int					cal_offset(t_stack *stack_a);
int					get_index(int *arr, int value, int size);
void				push_to_a(t_stack **stack_a, t_stack **stack_b);
void				push_to_b(t_stack **stack_a, t_stack **stack_b, int offset);
int					stack_len(t_stack *a);
void				numbers(t_stack **stack_a, t_stack **stack_b);
void				two(t_stack **stack_a);
void				three(t_stack **stack_a);
void				four(char **av, t_stack **stack_a, t_stack **stack_b);
void				ten(t_stack **stack_a, t_stack **stack_b);
void				large(t_stack **stack_a, t_stack **stack_b);
int					*sorted_bubble(int *arr, int len);
int					*sort_arr(t_stack **stack_a, int len);
void				parsing(int ac, char **av, t_stack **stack_a,
						t_stack **stack_b);
t_pos				*minimum_value(t_stack *stack_a);
char				**ft_split(char const *s, char c);
int					ft_atoi(char *nptr, char **numbers, int *stored_nums);
t_stack				*create_stack(int value);
void				push_stack(int value, t_stack **stack_a);
void				ft_print_stack(t_stack *stack);
int					ft_poop(t_stack **stack);
void				ft_free_stack(t_stack **stack);
void				free_and_exit(char **numbers, int *stored_nums);
int					count_total_numbers(char **av);
int					ft_isdigit(char *str);
void				ft_free(char **ptr);
void				error_and_free(char **numbers, int *stored_nums);

#endif