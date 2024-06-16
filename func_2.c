/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:16:52 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/12 13:19:06 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ss(t_var **a, t_var **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	swap(a, 't');
	swap(b, 't');
	write(1, "ss\n", 3);
}

void	rr(t_var **a, t_var **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rotate(a, 't');
	rotate(b, 't');
	write(1, "rr\n", 3);
}

void	rrr(t_var **a, t_var **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rev_rot(a, 't');
	rev_rot(b, 't');
	write(1, "rrr\n", 4);
}
