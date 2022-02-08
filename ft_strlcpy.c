/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:42 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 19:09:18 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len && i + 1 < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (src_len);
}
