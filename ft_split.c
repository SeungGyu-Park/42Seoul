/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:26 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/09 13:06:31 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_split_cnt(const char *s, char c, int *it, int *rt)
{
	size_t	row_cnt;
	size_t	i;

	row_cnt = 0;
	i = 0;
	*it = -1;
	*rt = -1;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			row_cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (row_cnt);
}

static char	**free_res(char **res)
{
	size_t	idx;

	idx = 0;
	while (res[idx])
		free(res[idx++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;
	int		ri;

	if (!s)
		return (NULL);
	res = (char **)malloc((find_split_cnt(s, c, &i, &ri) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			res[++ri] = ft_substr(s, i, len);
			if (res[ri] == NULL)
				return (free_res(res));
			i += len - 1;
		}
	}
	res[++ri] = NULL;
	return (res);
}
