/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:26 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/09 11:27:30 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_split_cnt(const char *s, char c)
{
	size_t	row_cnt;
	size_t	i;

	row_cnt = 0;
	i = 0;
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
	int		res_idx;

	if (!s)
		return (NULL);
	res = (char **)malloc((find_split_cnt(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	res_idx = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			res[++res_idx] = ft_substr(s, i, len);
			if (res[res_idx] == NULL)
				return (free_res(res));
			i += len - 1;
		}
	}
	res[++res_idx] = NULL;
	return (res);
}
