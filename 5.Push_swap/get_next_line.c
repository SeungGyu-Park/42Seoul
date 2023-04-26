/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:09:34 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/18 21:41:12 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char **line)
{
	int		ret;
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)malloc(5);
	if (!(buf) || !(line))
		return (-1);
	ret = read(0, &buf[i], 1);
	while (ret > 0 && buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
		ret = read(0, &buf[i], 1);
	}
	buf[i] = '\0';
	if (ret != -1)
		*line = buf;
	if (ret > 0)
		return (1);
	else
		return (ret);
}
