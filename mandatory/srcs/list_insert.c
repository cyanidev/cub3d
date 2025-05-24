/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andie <Andie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:55 by Andie             #+#    #+#             */
/*   Updated: 2025/03/08 21:55:41 by Andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "cub_render.h"

void	list_insrt_back(t_list *list, t_node *node_to_insrt, t_node *ref_node)
{
	t_node	*tmp_back;
	t_node	*tmp_front;

	tmp_front = ref_node;
	tmp_back = NULL;
	if (ref_node)
		tmp_back = ref_node->back;
	if (tmp_back)
		tmp_back->next = node_to_insrt;
	node_to_insrt->back = tmp_back;
	if (tmp_front)
		tmp_front->back = node_to_insrt;
	node_to_insrt->next = tmp_front;
	list->size++;
}

/*
	insrt in front of the referece node
*/
void	list_insrt_front(t_list *list, t_node *node_to_insrt, t_node *ref_node)
{
	t_node	*tmp_back;
	t_node	*tmp_front;

	tmp_back = ref_node;
	tmp_front = NULL;
	if (ref_node)
		tmp_front = ref_node->next;
	if (tmp_back)
		tmp_back->next = node_to_insrt;
	node_to_insrt->back = tmp_back;
	if (tmp_front)
		tmp_front->back = node_to_insrt;
	node_to_insrt->next = tmp_front;
	list->size++;
}
