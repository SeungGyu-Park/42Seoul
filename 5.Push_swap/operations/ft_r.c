/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:00:31 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/18 21:38:52 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_list **a, int i)
{
	t_list	*lst;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	lst = *a;
	*a = lst->next;
	lst->next = NULL;
	ft_lstadd_back(a, lst);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int i)
{
	t_list	*lst;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	lst = *b;
	*b = lst->next;
	lst->next = NULL;
	ft_lstadd_back(b, lst);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b, int i)
{
	ft_ra(a, i);
	ft_rb(b, i);
	if (i == 1)
		write(1, "rr\n", 3);
}
