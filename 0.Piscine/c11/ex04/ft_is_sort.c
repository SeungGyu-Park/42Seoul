/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:43:50 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/29 01:02:02 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	des;

	i = 0;
	asc = 0;
	des = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			asc++;
		if (f(tab[i], tab[i + 1]) > 0)
			des++;
	}
	if (asc == length - 1 || des == length - 1)
		return (1);
	return (0);
}
