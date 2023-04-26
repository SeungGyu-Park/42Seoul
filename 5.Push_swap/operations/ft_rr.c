/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:01:27 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/18 21:38:50 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*lst;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	lst = *a;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	ft_lstadd_front(a, tmp);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b, int i)
{
	t_list	*tmp;
	t_list	*lst;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	lst = *b;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	ft_lstadd_front(b, tmp);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b, int i)
{
	ft_rra(a, i);
	ft_rrb(b, i);
	if (i == 1)
		write(1, "rrr\n", 4);
}
