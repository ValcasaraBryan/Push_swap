/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:26:10 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/15 21:59:54 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error_val(t_data *data)
{
	free_tab_str(&SPLIT);
	ft_fprintf(MSG_ERR, S_ERR);
	return (ERROR);
}

int			error_arg(t_data *data)
{
	ft_fprintf(MSG_I, S_ERR, SPLIT[data->I] + 1);
	ft_fprintf(MSG_U, S_ERR, OPTION_);
	free_tab_str(&SPLIT);
	return (ERROR);
}

int			error_file(t_data *data)
{
	(void)data;
	ft_fprintf(F_NMIS, S_ERR);
	return (ERROR);
}

int			error_edit(t_data *data)
{
	(void)data;
	ft_fprintf(E_NMIS, S_ERR);
	return (ERROR);
}
