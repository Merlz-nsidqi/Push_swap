/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:44:18 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/15 14:12:59 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <libc.h>

typedef struct s_var
{
	struct s_var	*last;
	int				n;
	struct s_var	*next;
}	t_var;

char	**ft_split(char const *s, int j);
int		ft_atoi(char *str, int sign, int i);
t_var	*store(char **av, int g, int ac, int i);
void	swap(t_var **s, char w);
void	rotate(t_var **s, char w);
void	rev_rot(t_var **s, char w);
void	push_b(t_var **f, t_var **s, int *sa, int *sb);
int		sorted(t_var *s);
void	sort1(t_var **a, t_var **b, int p0, int size_a);
int		n(t_var *v);
void	sort_3(t_var **t);
void	sort2(t_var **a, t_var **b, int big);
void	push_a(t_var **b, t_var **a);
void	ss(t_var **a, t_var **b);
void	rr(t_var **a, t_var **b);
void	rrr(t_var **a, t_var **b);
t_var	*last(t_var *a);
void	num(t_var **a, int s_a, int i, int n);
void	sort_2(t_var **t);
int		up_o_down(t_var **a, int l, int p);
int		up_o_down2(t_var **a, int l, int p);

#endif
