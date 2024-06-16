/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:43:05 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/15 14:01:11 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	sorted(t_var *s)
{
	t_var	*current;

	if (s == NULL)
		return (0);
	current = s;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort2(t_var **a, t_var **b, int big)
{
	t_var	*t;

	while (!((*b) == NULL && sorted(*a) == 1))
	{
		while ((*b) != NULL && (*b)->n != (*a)->n - 1)
		{
			if (last(*a)->n < (*b)->n || last(*a)->n == big)
			{
				push_a(b, a);
				rotate(a, 'a');
			}
			else if (up_o_down2(b, n(*b) / 2, (*a)->n - 1) == 1)
				rotate(b, 'b');
			else if (up_o_down2(b, n(*b) / 2, (*a)->n - 1) == 0)
				rev_rot(b, 'b');
		}
		while ((*b) != NULL && (*b)->n == (*a)->n - 1)
			push_a(b, a);
		while (last(*a)->n == (*a)->n - 1)
			rev_rot(a, 'a');
	}
}

void	sort1(t_var **a, t_var **b, int p0, int size_a)
{
	int	size_b;
	int	p1;
	int	p2;

	p1 = size_a / 3;
	p2 = size_a / 6;
	size_b = 0;
	while (size_a > 3)
	{
		if ((*a)->n < p1)
			push_b(a, b, &size_a, &size_b);
		else if (up_o_down(a, size_a / 2, p1) == 1)
			rotate(a, 'a');
		else if (up_o_down(a, size_a / 2, p1) == 0)
			rev_rot(a, 'a');
		if (size_b >= 2 && (p0 < (*b)->n && (*b)->n < p2))
			rotate(b, 'b');
		if (size_b == p1)
		{
			p0 = p1;
			p1 += size_a / 3;
			p2 = size_a / 6 + p0;
		}
	}
	sort_3(a);
}

void	store2(t_var **var, t_var **head, t_var **current, char r[])
{
	*var = (t_var *)malloc(sizeof(t_var));
	(*var)->n = ft_atoi(r, 1, 0);
	(*var)->next = NULL;
	if (*head == NULL)
	{
		*head = *var;
		*current = *var;
	}
	else
	{
		(*current)->next = *var;
		(*var)->last = *current;
		*current = *var;
	}
	free(r);
}

t_var	*store(char **av, int g, int ac, int i)
{
	t_var	*head;
	t_var	*var;
	t_var	*current;
	char	**r;
	int		j;

	head = NULL;
	current = NULL;
	while (g < ac)
	{
		r = ft_split(av[g], 0);
		i = 0;
		j = 0;
		while (r[i] != NULL)
			i++;
		while (j < i)
		{
			store2(&var, &head, &current, r[j]);
			j++;
		}
		free(r);
		g++;
	}
	return (head);
}
