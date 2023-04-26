/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:09:56 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/29 00:18:01 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * length);
	if (!res)
		return (0);
	i = -1;
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
