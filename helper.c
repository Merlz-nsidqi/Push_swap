/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:27:34 by nsidqi            #+#    #+#             */
/*   Updated: 2024/06/15 14:01:19 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if (len > size - start)
		len = size - start;
	if (start > size)
		len = 0;
	res = malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	while (i < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	count(char const *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			r++;
		while (s[i] != ' ' && s[i])
			i++;
	}
	return (r);
}

int	ft_word(char const *s)
{
	int	word;
	int	i;

	i = 0 ;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
		{
			word++;
			i++;
		}
		if (s[i - 1] != ' ')
			return (word);
	}
	return (0);
}

char	**ft_split(char const *s, int j)
{
	char	**res;

	if (s == 0 || *s == '\0')
		return (write(2, "Error\n", 6), exit(0), NULL);
	while (*s == ' ')
		s++;
	res = malloc((count(s) + 1) * sizeof(char *));
	if (res == NULL || s == 0 || *s == '\0')
		return (write(2, "Error\n", 6), exit(0), NULL);
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != '\0')
		{
			res[j] = ft_substr(s, 0, ft_word(s));
			if (res[j] == NULL)
				return (exit(0), NULL);
			s += ft_word(s);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
