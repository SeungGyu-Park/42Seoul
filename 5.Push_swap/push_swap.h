/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:07:35 by seunggpa          #+#    #+#             */
/*   Updated: 2022/07/20 12:37:54 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

/*****OPERATIONS*****/
void	ft_sa(t_list *a, int i);
void	ft_sb(t_list *b, int i);
void	ft_ss(t_list *a, t_list *b, int i);
void	ft_ra(t_list **a, int i);
void	ft_rb(t_list **b, int i);
void	ft_rr(t_list **a, t_list **b, int i);
void	ft_rra(t_list **a, int i);
void	ft_rrb(t_list **b, int i);
void	ft_rrr(t_list **a, t_list **b, int i);
void	ft_pa(t_list **a, t_list **b, int i);
void	ft_pb(t_list **a, t_list **b, int i);

/*****FUNCTIONS*****/
void	ft_check_digit_error(char **argv, int i);
void	ft_check_repeat_error(int *c, int argc);
void	bubblesort(int *c, int size);
int		ft_check_order(t_list **a, int *c, int size);
void	ft_lstorder(t_list **a, int *c);
void	ft_error(void);
void	sort_small_stack(t_list **a, t_list **b, int *c, int arg);
void	sort_big_stack(t_list **a, t_list **b, int size);
void	ft_free(t_list **a, t_list **b, int *c);
int		get_next_line(char **line);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi2(const char *str);
void	tmp_free(char **tmp);
void	add_elem_to(char **tmp, int *arr, t_list **a, int *idx);
void	ft_do_sort(t_list **a, t_list **b, int *arr, int size);
#endif
