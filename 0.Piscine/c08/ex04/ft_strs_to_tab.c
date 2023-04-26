/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 02:42:15 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/27 18:36:19 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*res;
	 int	i;
	 int	len_src;

	if (src == 0)
		return (0);
	len_src = ft_strlen(src);
	res = malloc(len_src + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len_src)
	{
		res[i] = src[i];
		i++;
	}
	res[len_src] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	        int	i;
	t_stock_str	*charset;

	charset = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!charset)
		return (0);
	i = -1;
	while (++i < ac)
	{
		charset[i].size = ft_strlen(av[i]);
		charset[i].str = av[i];
		charset[i].copy = ft_strdup(av[i]);
	}
	charset[i].size = 0;
	charset[i].str = 0;
	charset[i].copy = 0;
	return (charset);
}
