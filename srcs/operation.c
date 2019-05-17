/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:38:46 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/17 14:07:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				s_ab(t_val **data, t_val *a, t_val *b)
{
	t_val		*prev;
	t_val		*next;

	if (!a && !b)
		return (0);
	prev = a->prev;
	next = b->next;
	if (prev == b && next == a)
	{
		a = a->next;
		*data = b;
		return (1);
	}
	prev->next = b;
	b->prev = prev;
	b->next = a;
	a->prev = b;
	a->next = next;
	next->prev = a;
	*data = b;
	return (1);
}
