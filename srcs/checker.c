/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 14:29:43 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checker(t_data *data)
{
	if (data->len <= 1)
		return (ERROR);
	while (data->index < data->len)
	{
		if (!(data->split = ft_strsplit(data->av[data->index], ' ')))
			return (ERROR);
		if (!(data->len_split = ft_len_tab_str(data->split)))
			return (error_arg(data));
		if (pars(data) == ERROR)
			return (ERROR);
		free_tab_str(&data->split);
		data->index++;
	}
	if (data->option[HELP])
		return (print_msg(data, data->option[HELP]));
	if (data->option[PATTERN])
		return (print_msg(data, data->option[PATTERN]));
	if (data->no_edit == TRUE)
		return (error_edit(data));
	if (data->no_file == TRUE)
		return (error_file(data));
	
	if (!(print_list(data, data->tab)))
		return (FALSE);
	return (TRUE);
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	init_data(&data, argc, argv);
	if ((ret = checker(&data)) == ERROR);
	else if (ret == FALSE)
		ft_fprintf("KO\n", S_STD);
	else if (ret == TRUE)
		ft_fprintf("OK\n", S_STD);
	erase_all(&data);
	return (FALSE);
}
