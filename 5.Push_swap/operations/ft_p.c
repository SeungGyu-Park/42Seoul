/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:20:38 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/18 21:38:55 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_list **a, t_list **b, int i)
{
	t_list	*lst;

	if (*b == NULL)
		return ;
	lst = *b;
	*b = lst->next;
	lst->next = NULL;
	ft_lstadd_front(a, lst);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b, int i)
{
	t_list	*lst;

	if (*a == NULL)
		return ;
	lst = *a;
	*a = lst->next;
	lst->next = NULL;
	ft_lstadd_front(b, lst);
	if (i == 1)
		write(1, "pb\n", 3);
}
