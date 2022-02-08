/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:53 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 19:29:16 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (*haystack != 0 && len > 0 && i <= len)
	{
		if (ft_strncmp(haystack, needle, i) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
