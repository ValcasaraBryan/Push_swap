/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:01:46 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 16:29:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			init_ope(t_data *data)
{
	data->operation[SA] = "sa";
	data->operation[SB] = "sb";
	data->operation[SS] = "ss";
	data->operation[PA] = "pa";
	data->operation[PB] = "pb";
	data->operation[RA] = "ra";
	data->operation[RB] = "rb";
	data->operation[RR] = "rr";
	data->operation[RRA] = "rra";
	data->operation[RRB] = "rrb";
	data->operation[RRR] = "rrr";
	return (1);
}

int			check_ope(t_data *data, char *str)
{
	int		i;

	i = -1;
	while (++i < LEN_OPE)
		if (ft_strcmp((const char *)data->operation[i], (const char *)str) == 0)
			return (1);
	return (0);
}