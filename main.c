/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:17:25 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/15 14:04:43 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	n(t_var *v)
{
	t_var	*tmp;
	int		i;

	i = 0;
	tmp = v;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	repeat(t_var *v)
{
	t_var	*outer;
	t_var	*inner;

	outer = v;
	while (outer != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->n == inner->n)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_var	*a;
	t_var	*b;
	int		s_a;

	if (ac > 1)
	{
		a = store(av, 1, ac, 0);
		s_a = n(a);
		if (repeat(a) == 1)
			return (write(2, "Error\n", 6), exit(1), 1);
		if (s_a < 2 || sorted(a) == 1)
			exit(0);
		num(&a, s_a, 0, 0);
		if (s_a == 2)
			sort_2(&a);
		else if (s_a == 3)
			sort_3(&a);
		else
		{
			sort1(&a, &b, -1, s_a);
			s_a = last(a)->n;
			sort2(&a, &b, s_a);
		}
	}
	return (exit(0), 0);
}
