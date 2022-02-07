/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:11 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/07 22:14:50 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *ptr, int value, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
		tmp[i++] = (unsigned char)value;
	return (tmp);
}
