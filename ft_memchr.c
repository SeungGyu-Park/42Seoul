/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:27:57 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/07 22:11:24 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (*((unsigned char *)ptr + i) == (unsigned char)value)
			return ((void *)(unsigned char *)ptr + i);
	return (NULL);
}
