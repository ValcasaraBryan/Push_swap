/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:38:46 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 17:50:11 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap(void **a, void **b)
{
	void		*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				sa(t_data *data)
{
	t_val		*prev;
	t_val		*current;
	t_val		*next;

	if (!data->a || !data->a->next)
		return (0);
	prev = data->a->prev;
	current = data->a;
	next = data->a->next;
	ft_printf("avant\n");
	ft_printf("%p <-- %p --> %p| prev\n", prev->prev, prev, prev->next);
	ft_printf("%p <-- %p --> %p| current\n", current->prev, current, current->next);
	ft_printf("%p <-- %p --> %p| next\n", next->prev, next, next->next);
	
	ft_printf("apres\n");
	ft_printf("%p <-- %p --> %p| prev\n", prev->prev, prev, prev->next);
	ft_printf("%p <-- %p --> %p| current\n", current->prev, current, current->next);
	ft_printf("%p <-- %p --> %p| next\n", next->prev, next, next->next);
	return (1);
}