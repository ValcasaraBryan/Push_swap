/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:26:10 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/17 13:28:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error(t_data *data)
{
	if (FLAG_O[HELP])
		return (print_msg(data, FLAG_O[HELP]));
	if (FLAG_O[PATTERN])
		return (print_msg(data, FLAG_O[PATTERN]));
	if (EDIT_ == TRUE)
		return (error_edit(data));
	if (FILE == TRUE)
		return (error_file(data));
	if (!data->a)
		return (ERROR);
	return (TRUE);
}

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
