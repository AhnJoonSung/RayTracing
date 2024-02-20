/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:43 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/20 20:22:29 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// del : node의 content에 적용할 함수
void	ft_list_clear(t_list *list, void (*del)(void *))
{
	t_node	*node;
	t_node	*temp;

	if (list == 0)
		return ;
	node = list->head;
	while (node)
	{
		temp = node->next;
		del(node->content);
		free(node);
		node = temp;
	}
	free(list);
	list = 0;
}
