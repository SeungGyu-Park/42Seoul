/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:17:02 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/18 21:36:49 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_2(t_list **lst)
{
	t_list	*tmp;
	t_list	*element;

	element = *lst;
	tmp = NULL;
	if (!lst || !*lst)
		return ;
	while (element)
	{
		if (element->next)
			tmp = element->next;
		else
			tmp = NULL;
		if (element->content != 0)
			element->content = 0;
		if (element->order != 0)
			element->order = 0;
		free(element);
		element = tmp;
	}
	*lst = NULL;
}

void	ft_free(t_list **a, t_list **b, int *c)
{
	ft_lstclear_2(a);
	ft_lstclear_2(b);
	free(c);
	c = NULL;
}
