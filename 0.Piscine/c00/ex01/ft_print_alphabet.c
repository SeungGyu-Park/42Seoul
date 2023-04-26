/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:37:06 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/21 01:21:49 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	lower_ch;

	lower_ch = 'a';
	while (lower_ch <= 'z')
	{
		write(1, &lower_ch, 1);
		lower_ch++;
	}
}
