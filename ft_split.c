/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:26 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 20:22:31 by seunggpa         ###   ########.fr       */
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
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else if (s[i] != c)
		{
			row_cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (row_cnt);
}

static size_t	find_str_len(char const *s, char c, size_t *s_len)
{
	size_t	start;
	size_t	end;
	size_t	s_idx;

	start = 0;
	end = 0;
	s_idx = 0;
	while (s[s_idx] == c)
		s_idx++;
	end = s_idx;
	*s_len = end - start;
	return (s_idx);
}

static char	**free_res(char **res)
{
	size_t	idx;

	idx = 0;
	while (*(res + idx))
		free(*(res + idx));
	free(res);
	return ((char **)0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	s_idx;
	size_t	s_len;
	size_t	row_cnt;
	size_t	row_idx;

	if (s == NULL)
		return (0);
	row_cnt = find_split_cnt(s, c);
	res = (char **)malloc((row_cnt + 1) * sizeof(char *));
	if (!res)
		return (0);
	s_idx = 0;
	row_idx = 0;
	while (row_idx < row_cnt)
	{
		s_idx += find_str_len(s + s_idx, c, &s_len);
		res[row_idx] = (char *)malloc(s_len + 1);
		if (!res[row_idx])
			return (free_res(res));
		ft_strlcpy(res[row_idx++], s + s_idx - s_len, s_len + 1);
	}
	res[row_idx] = NULL;
	return (res);
}
