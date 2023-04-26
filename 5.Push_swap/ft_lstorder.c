/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:23:57 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/19 16:53:36 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstorder(t_list **a, int *c)
{
	int		i;
	t_list	*lst;

	lst = *a;
	while (lst)
	{
		i = 0;
		while (lst->content != c[i])
		{
			i++;
		}
		lst->order = i;
		lst = lst->next;
	}
}
