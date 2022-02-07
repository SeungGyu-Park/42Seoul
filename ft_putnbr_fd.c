/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:28:21 by seunggpa          #+#    #+#             */
/*   Updated: 2022/02/07 22:21:02 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnber_fd(int n, int fd)
{
	char	*str;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483638", 11);
		return ;
	}
	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
	return ;
}
