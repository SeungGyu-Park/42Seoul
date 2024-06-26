/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:21:41 by seunggpa          #+#    #+#             */
/*   Updated: 2021/09/23 16:21:42 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_put_argv(char *argv[])
{
	int		idx;

	idx = 1;
	while (argv[idx])
	{
		ft_putstr(argv[idx]);
		write(1, "\n", 1);
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	int		idx1;
	int		idx2;
	char	*temp;

	idx1 = 1;
	while (idx1 < argc - 1)
	{
		idx2 = idx1 + 1;
		while (idx2 < argc)
		{
			if (ft_strcmp(argv[idx1], argv[idx2]) > 0)
			{
				temp = argv[idx1];
				argv[idx1] = argv[idx2];
				argv[idx2] = temp;
			}
			idx2++;
		}
		idx1++;
	}
	ft_put_argv(argv);
	return (0);
}
