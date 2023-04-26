/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:05 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 02:03:52 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_mem;
	unsigned char	*src_mem;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest_mem = (unsigned char *)dest;
	src_mem = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(dest_mem)++ = *(src_mem)++;
		i++;
	}
	return (dest);
}
