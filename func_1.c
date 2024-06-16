/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:16:55 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/12 13:33:02 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	swap(t_var **s, char w)
{
	int	f;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	f = (*s)->n;
	(*s)->n = (*s)->next->n;
	(*s)->next->n = f;
	if (w == 'a')
		write(1, "sa\n", 3);
	else if (w == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_var **s, char w)
{
	int		f;
	t_var	*tmp_b;

	f = (*s)->n;
	tmp_b = *s;
	while (tmp_b->next != NULL)
	{
		tmp_b->n = tmp_b->next->n;
		tmp_b = tmp_b->next;
	}
	tmp_b->n = f;
	tmp_b->next = NULL;
	if (w == 'a')
		write(1, "ra\n", 3);
	else if (w == 'b')
		write(1, "rb\n", 3);
}

void	rev_rot(t_var **s, char w)
{
	t_var	*last;
	t_var	*second_last;

	last = *s;
	second_last = NULL;
	if (*s == NULL || (*s)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *s;
	second_last->next = NULL;
	*s = last;
	if (w == 'a')
		write(1, "rra\n", 4);
	else if (w == 'b')
		write(1, "rrb\n", 4);
}

void	push_b(t_var **a, t_var **b, int *sa, int *sb)
{
	t_var	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	if (*b != NULL)
		(*b)->last = tmp;
	tmp->next = *b;
	*b = tmp;
	(*b)->last = NULL;
	(*sa)--;
	(*sb)++;
	write(1, "pb\n", 3);
}

void	push_a(t_var **b, t_var **a)
{
	t_var	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	if (*a != NULL)
		(*a)->last = tmp;
	tmp->next = *a;
	*a = tmp;
	(*a)->last = NULL;
	write(1, "pa\n", 3);
}
