/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:14:15 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 15:17:53 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			pars(t_data *data)
{
	int		ret;

	data->I = -1;
	ret = TRUE;
	while (++data->I < data->len_split)
	{
		if (OPT == TRUE)
			if (check_option(data) == ERROR)
				return (ERROR);
		if (FLAG_O[HELP])
			return (print_msg(data, FLAG_O[HELP]));
		else if (FLAG_O[PATTERN])
			return (print_msg(data, FLAG_O[PATTERN]));
		if (EDIT_ == ERROR)
			if (open_edit(data) == ERROR)
				return (ERROR);
		if (OPT == FALSE)
			if ((ret = check_no_option(data)) == ERROR)
				return (ERROR);
		if (ret == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int			check_option(t_data *data)
{
	if (ft_is_option(SPLIT[data->I], OPTION_))
	{
		if (active_option(data, 0, 0) == ERROR)
			return (ERROR);
	}
	else if (!ft_is_option(SPLIT[data->I], OPTION_)
		&& !ft_is_option(SPLIT[data->I], FILE_OP)
			&& SPLIT[data->I][0] == '-')
		return (error_arg(data));
	else if (EDIT_ == TRUE && !ft_is_option(SPLIT[data->I], FILE_OP))
	{
		data->edit = ft_strdup(SPLIT[data->I]);
		EDIT_ = ERROR;
	}
	else
		OPT = FALSE;
	return (TRUE);
}

int			check_no_option(t_data *data)
{
	if (ft_is_option(SPLIT[data->I], FILE_OP) && FILE == FALSE)
	{
		if (active_no_option(data, 0) == ERROR)
			return (ERROR);
	}
	else if (FILE == TRUE)
	{
		if (open_file(data) == ERROR)
			return (ERROR);
	}
	else if (ft_number_ok(SPLIT[data->I]))
	{
		if (!(data->a = intsplit(data->a, SPLIT[data->I], ' ')))
			return (FALSE);
	}
	else if (ft_is_option(SPLIT[data->I], OPTION_)
		|| SPLIT[data->I][0] != '-')
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
