/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:27:25 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 19:41:03 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
		++digit;
	while (n != 0)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}

static void	ft_insert_integer(char *res, long *res_idx, long long n)
{
	if (n == 0)
		return ;
	ft_insert_integer(res, res_idx, n / 10);
	res[(*res_idx)++] = '0' + (n % 10);
	return ;
}

char	*ft_itoa(int n)
{
	char		*res;
	long		len;
	long		res_idx;
	long long	n_tmp;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res_idx = 0;
	n_tmp = n;
	if (n < 0)
	{
		res[res_idx++] = '-';
		n_tmp *= -1;
	}
	ft_insert_integer(res, &res_idx, n_tmp);
	res[res_idx] = 0;
	return (res);
}
