/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:53:00 by edetoh            #+#    #+#             */
/*   Updated: 2024/10/25 11:19:33 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strtrim deletes specified characters.
 * Takes 'str' (source string) and 'str_del' (characters to be deleted).
 * Returns a new string without the specified characters.
 */

static int	ft_is_a_del(char caract, char const *str_del)
{
	int	i;

	i = 0;
	while (str_del[i] != '\0')
	{
		if (str_del[i] == caract)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_trim(char const *str, char const *str_del)
{
	char	*trimmed;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && ft_is_a_del(str[i], str_del) == 1)
	{
		i++;
	}
	trimmed = malloc(((ft_strlen(str) - i) + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	while (str[i] != '\0')
	{
		trimmed[n] = str[i];
		n++;
		i++;
	}
	trimmed[n] = 0;
	return (trimmed);
}

static char	*ft_trim_rev(char const *str, char const *str_del)
{
	char	*trimmed;
	size_t	str_len;
	size_t	del_len;
	size_t	i;

	str_len = (size_t)ft_strlen((char *)str);
	i = str_len;
	del_len = 0;
	while (i > 0 && ft_is_a_del(str[i - 1], str_del) == 1)
	{
		del_len++;
		i--;
	}
	trimmed = ft_substr(str, 0, (str_len - del_len));
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	char	*trimmed2;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
		return (ft_strdup(""));
	if (set[0] == 0)
		return (ft_strdup(s1));
	trimmed = ft_trim(s1, set);
	if (!trimmed)
		return (NULL);
	trimmed2 = ft_trim_rev(trimmed, set);
	free(trimmed);
	return (trimmed2);
}

// #include  <string.h>
// #include  <stdio.h>
// #include  <unistd.h>

// int main(void)
// {
// 	char *str = "ab cd  f    ";
// 	char *del = " ";

// 	char *res = ft_strtrim(str, del);

// 	printf("d===== RESULTTTT =====\n%s\n==================", res);
// 	free(res);
// 	return (1);
// }
