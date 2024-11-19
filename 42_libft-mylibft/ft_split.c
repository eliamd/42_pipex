/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:31:59 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:16:14 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * tab_malloc allocates and copies a substring.
 * Takes 'str' (source string), 'start' (start index),
 * len' (substring length) and 'tab' (string array).
 * Returns the substring or NULL on error.
 */

static char	*malloc_tab(const char *str, int start, int len)
{
	char	*sub;

	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)str + start, len + 1);
	return (sub);
}

static int	count_words(char const *str, char del)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == del)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != del)
			i++;
	}
	return (count);
}

static char	**malloc_main_tab(char **tab, char const *str, char del)
{
	if (str[0] == '\0')
	{
		tab = malloc(1 * sizeof(char *));
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc(((count_words(str, del) + 1) * sizeof(char *)));
	if (!tab)
		return (NULL);
	return (tab);
}

static int	fill_tab(char const *str, char del, char **tab)
{
	int		i;
	int		n;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i] == del)
			i++;
		while (str[i + n] != '\0' && str[i + n] != del)
			n++;
		if (n != 0)
			tab[k++] = malloc_tab(str, i, n);
		if ((k > 0 && tab[k - 1] == NULL) || !tab)
			return (0);
		i = i + n;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tab = NULL;
	tab = malloc_main_tab(tab, s, c);
	if (!tab)
		return (NULL);
	if (fill_tab(s, c, tab) == 0)
	{
		while (tab[i] != NULL)
			free(tab[i++]);
		free(tab);
		return (NULL);
	}
	return (tab);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int	main(void)
// {
// 	char *str = "bonjourzbonjourzbuhuhuzgyguhzohh";
// 	char del = 'z';
// 	int i = 0;

// 	char **res = ft_split(str, del);

// 	printf("===== RESULT =====\n");
// 	while (res[i] != NULL)
// 	{
// 		printf("Tab DE %i : %s\n", i, res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	printf("==================\n");
// 	free(res);
// 	return (1);
// }
