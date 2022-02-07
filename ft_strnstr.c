/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:53 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/08 02:02:58 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (len == 0 || len < h_len || h_len == 0)
		return (NULL);
	i = 0;
	while (i < len - n_len + 1)
	{
		if (*(haystack + i) == *(needle))
		{
			if (ft_strncmp(haystack + i, needle, n_len) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
