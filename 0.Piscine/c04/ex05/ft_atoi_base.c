/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:17:59 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/25 16:26:41 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	make_idx(char ch, int ibase, char *base)
{
	int	i;

	i = 0;
	while (i < ibase)
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	find_ibase(char *base)
{
	 int	i;
	char	ch[255];

	i = -1;
	while (++i < 255)
		ch[i] = 0;
	i = -1;
	while (base[++i])
	{
		if (ch[(int)base[i]] || base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || ('\t' <= base[i] && base[i] <= '\r'))
			return (-1);
		ch[(int)base[i]] = 1;
	}
	if (i < 2)
		return (-1);
	return (i);
}

char	*make_sign(char *str, int *sign)
{
	*sign = 1;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			*sign = -(*sign);
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ibase;
	int	sign;
	int	res;
	int	i;

	ibase = find_ibase(base);
	if (ibase <= 1)
		return (0);
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	str = make_sign(str, &sign);
	res = 0;
	while (*str)
	{
		i = make_idx(*(str++), ibase, base);
		if (i == -1)
			break ;
		res *= ibase;
		res += (sign * i);
	}
	return (res);
}
