/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:37:21 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/19 13:37:28 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_list **a)
{
	if ((*a)->content < (*a)->next->content && \
	(*a)->content < (*a)->next->next->content && \
	(*a)->next->content > (*a)->next->next->content)
	{
		ft_sa(*a, 1);
		ft_ra(a, 1);
	}
	else if ((*a)->content > (*a)->next->content \
	&& (*a)->content < (*a)->next->next->content)
		ft_sa(*a, 1);
	else if ((*a)->content < (*a)->next->content \
	&& (*a)->content > (*a)->next->next->content)
		ft_rra(a, 1);
	else if ((*a)->content > (*a)->next->content \
	&& (*a)->content > (*a)->next->next->content \
	&& (*a)->next->content < (*a)->next->next->content)
		ft_ra(a, 1);
	else if ((*a)->content > (*a)->next->content \
	&& (*a)->next->content > (*a)->next->next->content)
	{
		ft_sa(*a, 1);
		ft_rra(a, 1);
	}
}

void	ft_find_min(t_list **a, int *c, int order, int size)
{
	t_list	*lst;
	int		index;

	lst = *a;
	index = 0;
	while (lst->content != c[order])
	{
		lst = lst->next;
		index++;
	}
	if (index > size / 2)
	{
		while ((*a)->content != c[order])
			ft_rra(a, 1);
	}
	else
	{
		while ((*a)->content != c[order])
			ft_ra(a, 1);
	}
}

void	ft_sort_4(t_list **a, t_list **b, int *c, int size)
{
	ft_find_min(a, c, 0, size);
	ft_pb(a, b, 1);
	ft_sort_3(a);
	ft_pa(a, b, 1);
}

void	ft_sort_5(t_list **a, t_list **b, int *c, int size)
{
	ft_find_min(a, c, 0, size);
	ft_pb(a, b, 1);
	ft_find_min(a, c, 1, size);
	ft_pb(a, b, 1);
	ft_sort_3(a);
	ft_pa(a, b, 1);
	ft_pa(a, b, 1);
}

void	sort_small_stack(t_list **a, t_list **b, int *c, int size)
{
	if (size == 2)
		ft_sa(*a, 1);
	else if (size == 3)
		ft_sort_3(a);
	else if (size == 4)
		ft_sort_4(a, b, c, size);
	else if (size == 5)
		ft_sort_5(a, b, c, size);
}
