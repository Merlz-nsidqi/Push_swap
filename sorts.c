/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:04:45 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/14 17:33:19 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	sort_2(t_var **t)
{
	if ((*t)->n > (*t)->next->n)
		swap(t, 'a');
}

void	sort_3(t_var **t)
{
	while (sorted(*t) == 0)
	{
		if ((*t)->n > (*t)->next->next->n && (*t)->n > (*t)->next->n)
			rotate(t, 'a');
		else if ((*t)->n > (*t)->next->next->n
			|| (*t)->next->n > (*t)->next->next->n)
			rev_rot(t, 'a');
		else if ((*t)->n < (*t)->next->next->n
			|| (*t)->next->n < (*t)->next->next->n)
			swap(t, 'a');
	}
}

t_var	*last(t_var *a)
{
	t_var	*tmp;

	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	up_o_down(t_var **a, int l, int p)
{
	int		i;
	t_var	*t;

	i = 0;
	t = *a;
	while (t != NULL)
	{
		if (t->n < p)
		{
			if (i <= l)
				return (1);
			else
				return (0);
		}
		i++;
		t = t->next;
	}
	return (1);
}

int	up_o_down2(t_var **b, int l, int p)
{
	int		i;
	t_var	*t;

	i = 0;
	t = *b;
	while (t != NULL)
	{
		if (t->n == p)
		{
			if (i <= l)
				return (1);
			else
				return (0);
		}
		i++;
		t = t->next;
	}
	return (-1);
}
