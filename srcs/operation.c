/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:38:46 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 18:49:04 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sa(t_val *a, t_val *b)
{
	t_val		*prev;
	t_val		*next;

	if (!a->next)
		return (1);
	prev = a->prev;
	next = b->next;
	if (prev == b && next == a)
	{
		a = a->next;
		return (1);
	}
	prev->next = b;
	b->prev = prev;
	b->next = a;
	a->prev = b;
	a->next = next;
	next->prev = a;
	return (1);
}
