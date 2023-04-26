/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 01:22:24 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/25 01:22:24 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_total_strlen(char **s, int size)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (++i < size)
	{
		j = 0;
		while (s[i][j++])
			len++;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *res, char *str)
{
	while (*str)
	{
		*(res++) = *(str++);
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	char	*res;
	 int	i;

	if (size == 0)
	{
		res = (char *)malloc(1);
		if (!res)
			return (0);
		res[0] = '\0';
		return (res);
	}
	i = ft_total_strlen(strs, size);
	res = (char *)malloc((i + (size - 1) * ft_strlen(sep) + 1));
	if (!res)
		return (0);
	tmp = ft_strcat(res, strs[0]);
	i = 0;
	while (++i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i]);
	}
	*tmp = '\0';
	return (res);
}
