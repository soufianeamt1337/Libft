/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:55:29 by samajat           #+#    #+#             */
/*   Updated: 2021/11/16 08:28:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	t_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (str_tab[j]);
		j++;
	}
	free(str_tab);
}

static int	totalwords(char *str, char c)
{
	int		result;
	size_t	i;
	int		a;

	result = 0;
	i = 0;
	a = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			a = 1;
		}
		if (a)
			result++;
		a = 0;
	}
	return (result);
}

static char	*fill(char c, char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	s = (char *) malloc (sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

static void	split(char **f_s, char c, int size, char *str)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		while (*str && *str == c)
			str++;
		f_s[i] = fill(c, str);
		if (!f_s[i])
		{
			t_free (f_s, i);
			return ;
		}
		while (*str && *str != c)
			str++;
	}
	f_s[size] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**f_s;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	str = (char *)s;
	f_s = (char **) malloc (sizeof(char *) * (totalwords((char *)s, c) + 1));
	if (!f_s)
		return (NULL);
	split(f_s, c, totalwords((char *)s, c), str);
	return (f_s);
}
// #include<stdio.h>
// int main()
// {
//     char **tab;
//     int i = 0;
//     tab = ft_split("      ahammam     hghghgh dfhfghf ", ' ');
// 	// int a  = totalwords(" ggf gggg ", ' ');
//     while(tab[i])
//     {
//         printf (" %s\n", tab[i]);
//         i++;
//     }
//     return 0;
// }
