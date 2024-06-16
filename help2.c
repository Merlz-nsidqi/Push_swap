/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:19:52 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/15 13:44:13 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_atoi(char *str, int sign, int i)
{
	long	res;

	res = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (str[i] - '0') + (res * 10);
			i++;
		}
		else
			return (write(2, "Error\n", 6), exit(1), 0);
	}
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (write(2, "Error\n", 6), exit(1), 0);
	return (res * sign);
}

int	*ntwo(int s_a, int i, int *t)
{
	int	*rank;
	int	j;

	rank = malloc(sizeof(int) * (s_a + 1));
	if (rank == NULL)
		return (exit(0), NULL);
	while (i++ <= s_a)
		rank[i] = 0;
	i = 0;
	while (i < s_a)
	{
		j = 0;
		while (j < s_a)
		{
			if (t[i] > t[j])
				rank[i]++;
			j++;
		}
		i++;
	}
	i = -1;
	while (i++ < s_a)
		t[i] = rank[i];
	return (free(rank), t);
}

void	num(t_var **a, int s_a, int i, int n)
{
	int		*t;
	t_var	*v;

	v = *a;
	t = malloc(sizeof(int) * (s_a + 1));
	if (t == NULL)
		exit(0);
	while (v != NULL)
	{
		t[i] = v->n;
		i++;
		v = v->next;
	}
	t = ntwo(s_a, -1, t);
	v = *a;
	i = 0;
	while (*a != NULL)
	{
		(*a)->n = t[i];
		i++;
		*a = (*a)->next;
	}
	*a = v;
	free(t);
}
