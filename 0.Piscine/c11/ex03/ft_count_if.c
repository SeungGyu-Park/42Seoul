/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:35:14 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/29 00:43:20 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
	}
	return (cnt);
}
