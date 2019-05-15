/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 00:35:26 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checker(int ac, char **av)
{
	t_data	data;

	init_data(&data, ac, av);
	if (data.len <= 1)// ARG NO
		return (ERROR);
	while (data.index < data.len) // ARG OUI
	{
		if (!(data.split = ft_strsplit(data.av[data.index], ' ')))
			return (ERROR);
		if (!(data.len_split = ft_len_tab_str(data.split)))
			return (error_arg(&data));
		if (pars(&data) == ERROR)
			return (ERROR);
		free_tab_str(&data.split);
		data.index++;
	}
	if (data.option[HELP])
		return (print_msg(&data, data.option[HELP]));
	if (data.option[PATTERN])
		return (print_msg(&data, data.option[PATTERN]));
	if (data.no_edit == TRUE)
		return (error_edit(&data));
	if (data.no_file == TRUE)
		return (error_file(&data));
	print_list(&data, data.tab);
	erase_list(&data.tab);
	return (TRUE);
}

int			main(int argc, char **argv)
{
	int		ret;

	if ((ret = checker(argc, argv)) == ERROR)
		return (FALSE);
	else if (ret == FALSE)
		ft_fprintf("KO\n", S_STD);
	else if (ret == TRUE)
		ft_fprintf("OK\n", S_STD);
	return (FALSE);
}
