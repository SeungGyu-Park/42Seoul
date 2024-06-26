/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:18:26 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/23 16:18:27 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	a;
	int	b;

	b = nb / 2;
	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	a = 2;
	while (a <= b)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}
