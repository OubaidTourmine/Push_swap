/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:25:29 by outourmi          #+#    #+#             */
/*   Updated: 2025/02/06 15:29:19 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while ((s[i] == c))
			i++;
		if (s[i])
			counter++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (counter);
}

char	*ft_dup(char const *s, char c)
{
	int		len;
	int		i;
	char	*a;

	len = 0;
	i = 0;
	while ((s[len] != c) && s[len])
