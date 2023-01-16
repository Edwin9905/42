/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:08:26 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/09 19:24:29 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_info *info)
{
	t_node	*tmp;

	tmp = info->tail;
	modify_idx(info, 1);
	tmp->idx = 0;
	tmp->next = info->head;
	info->tail = tmp->pre;
	tmp->pre->next = 0;
	tmp->next = info->head;
	info->head->pre = tmp;
	info->head = tmp;
}

void	rra(t_info *info)
{
	if (info->size < 2)
		return ;
	reverse_rotate(info);
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	if (info->size < 2)
		return ;
	reverse_rotate(info);
	write(1, "rra\n", 4);
}

void	rrr(t_info *info_a, t_info *info_b)
{
	if (info_a->size < 2 || info_b->size < 2)
		return ;
	reverse_rotate(info_a);
	reverse_rotate(info_b);
	write(1, "rrr\n", 4);
}