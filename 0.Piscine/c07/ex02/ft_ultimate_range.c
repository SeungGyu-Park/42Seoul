/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 01:22:21 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/25 01:22:22 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*tmp;

	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len + 1);
	if (!*range)
		return (0);
	tmp = *range;
	while (min < max)
	{
		*(tmp++) = min++;
	}
	return (len);
}
