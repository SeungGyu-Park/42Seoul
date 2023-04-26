/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:47:29 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/20 12:45:08 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_and_sort(t_list **a, t_list **b, int *arr, int size)
{
	ft_check_repeat_error(arr, size);
	bubblesort(arr, size);
	if (ft_check_order(a, arr, size - 1))
		exit (EXIT_SUCCESS);
	ft_lstorder(a, arr);
	if (size <= 5)
		sort_small_stack(a, b, arr, size);
	else
		sort_big_stack(a, b, size);
}

void	ft_init(char **argv, int argc, int i, int len)
{
	t_list	*a;
	t_list	*b;
	int		*arr;
	int		idx;
	char	**tmp;

	a = NULL;
	b = NULL;
	arr = malloc(sizeof(int) * (len));
	if (arr == NULL)
		exit (1);
	idx = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		add_elem_to(tmp, arr, &a, &idx);
		tmp_free(tmp);
	}
	ft_check_and_sort(&a, &b, arr, ft_lstsize(a));
	ft_free(&a, &b, arr);
}

void	add_elem_to(char **tmp, int *arr, t_list **a, int *idx)
{
	int		j;

	j = -1;
	while (tmp[++j])
	{
		arr[(*idx)] = ft_atoi2(tmp[j]);
		ft_lstadd_back(a, ft_lstnew(ft_atoi2(tmp[j])));
		(*idx)++;
	}
}

void	tmp_free(char **tmp)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (tmp[++i])
		len++;
	i = -1;
	while (++i < len)
		free(tmp[i]);
	free(tmp);
}

int	main(int argc, char **argv)
{
	int		len;
	int		i;
	int		j;
	char	**tmp;

	if (argc < 2)
		return (0);
	i = 0;
	len = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || !argv[i])
			ft_error();
		j = -1;
		while (tmp[++j])
		{
			ft_check_digit_error(tmp, j);
			len++;
		}
		tmp_free(tmp);
	}
	ft_init(argv, argc, 0, len);
	return (0);
}
