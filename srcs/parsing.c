/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:14:15 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 00:43:39 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			pars(t_data *data)
{
	data->I = -1;
	while (++data->I < data->len_split)
	{
		printf("%-10s FLAG_O[%d] EDIT_[%d]\n", SPLIT[data->I], FLAG_O[EDIT], EDIT_);
		if (OPT == TRUE)// OPT TRUE OUI
			if (check_option(data) == ERROR)
				return (ERROR);
		printf("%-10s FLAG_O[%d] EDIT_[%d]\n", SPLIT[data->I], FLAG_O[EDIT], EDIT_);
		if (OPT == FALSE)// OPT TRUE NON
			if (check_no_option(data) == ERROR)
				return (ERROR);
		printf("%-10s FLAG_O[%d] EDIT_[%d]\n", SPLIT[data->I], FLAG_O[EDIT], EDIT_);
	}
	return (TRUE);
}

int			check_option(t_data *data)
{
	if (ft_is_option(SPLIT[data->I], OPTION_))// CORRECT OUI
	{
		if (active_option(data, 0, 0) == ERROR)
			return (ERROR);
	}
	else if (EDIT_ == TRUE)
	{
		data->edit = ft_strdup(SPLIT[data->I]);
		EDIT_ = ERROR;
	}
	else if (!ft_is_option(SPLIT[data->I], OPTION_)
		&& !ft_is_option(SPLIT[data->I], FILE_OP)
			&& SPLIT[data->I][0] == '-')
		return (error_arg(data));
	else
		OPT = FALSE;
	return (TRUE);
}

int			check_no_option(t_data *data)
{
	if (FLAG_O[HELP])
		return (print_msg(data, FLAG_O[HELP]));
	else if (FLAG_O[PATTERN])
		return (print_msg(data, FLAG_O[PATTERN]));
	if (EDIT_ == ERROR)
	{
		EDIT_ = FALSE;
		if (open_edit(data) == ERROR)
			return (ERROR);
	}
	if (ft_is_option(SPLIT[data->I], FILE_OP) && FILE == FALSE)
	{
		if (active_no_option(data, 0) == ERROR)
			return (ERROR);
	}
	else if (FILE == TRUE)
	{
		if (open_file(data) == ERROR)
			return (ERROR);
		FILE = FALSE;
	}
	else if (ft_number_ok(SPLIT[data->I]))
	{
		ft_printf("%s\n", SPLIT[data->I]);
		data->tab = intsplit(data->tab, SPLIT[data->I], ' ');
	}
	else if (ft_is_option(SPLIT[data->I], OPTION_) || SPLIT[data->I][0] != '-')
		return (error_val(data));
	else
		return (error_arg(data));
	return (TRUE);
}

int			active_option(t_data *data, int i, int a)
{
	while (SPLIT[data->I][++i])
	{
		a = ft_strnchr(OPTION_, SPLIT[data->I][i], LEN_OPTION);
		if (FLAG_O[a] == FALSE)
			FLAG_O[a] = TRUE;
		else if (FLAG_O[a] == TRUE)
			return (error_arg(data));
		if (FLAG_O[EDIT] == TRUE)
			EDIT_ = TRUE;
	}
	return (TRUE);
}

int			active_no_option(t_data *data, int i)
{
	int		flag;

	flag = FALSE;
	while (SPLIT[data->I][++i])
	{
		if (params(SPLIT[data->I][i], FILE_OP) == TRUE && flag == FALSE)
		{
			FILE = TRUE;
			flag = TRUE;
		}
		else
			return (error_arg(data));
	}
	return (TRUE);
}
