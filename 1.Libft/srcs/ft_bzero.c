/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:27:04 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/09 10:43:41 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	if (!s)
		return ;
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(dest++) = 0;
		i++;
	}
}
