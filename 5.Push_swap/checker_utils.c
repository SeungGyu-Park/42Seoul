/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:04:01 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/20 12:33:00 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_oper(t_list **a, t_list **b, char *oper)
{
	if (!ft_strcmp(oper, "sa"))
		ft_sa(*a, 0);
	else if (!ft_strcmp(oper, "sb"))
		ft_sb(*b, 0);
	else if (!ft_strcmp(oper, "ss"))
		ft_ss(*a, *b, 0);
	else if (!ft_strcmp(oper, "ra"))
		ft_ra(a, 0);
	else if (!ft_strcmp(oper, "rb"))
		ft_rb(b, 0);
	else if (!ft_strcmp(oper, "rr"))
		ft_rr(a, b, 0);
	else if (!ft_strcmp(oper, "rra"))
		ft_rra(a, 0);
	else if (!ft_strcmp(oper, "rrb"))
		ft_rrb(b, 0);
	else if (!ft_strcmp(oper, "rrr"))
		ft_rrr(a, b, 0);
	else if (!ft_strcmp(oper, "pa"))
		ft_pa(a, b, 0);
	else if (!ft_strcmp(oper, "pb"))
		ft_pb(a, b, 0);
	else
		ft_error();
}

void	ft_do_sort(t_list **a, t_list **b, int *arr, int size)
{
	char	*oper;

	if (a && arr)
	{
		while (get_next_line(&oper) > 0)
		{
			ft_do_oper(a, b, oper);
			free(oper);
		}
		free(oper);
		if (ft_check_order(a, arr, size - 1) && !*b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
