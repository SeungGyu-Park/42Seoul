/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:44:54 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/21 20:16:53 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] >= ' ' && str[index] <= '~'))
			return (0);
		index++;
	}
	return (1);
}
