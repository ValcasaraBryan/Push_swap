/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 15:16:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checker(t_data *data)
{
	int		ret;

	if (data->len <= 1)
		return (ERROR);
	while (++data->index < data->len)
	{
		if (!(data->split = ft_strsplit(data->av[data->index], ' ')))
			return (ERROR);
		if (!(data->len_split = ft_len_tab_str(data->split)))
			return (error_arg(data));
		if ((ret = pars(data)) == ERROR)
			return (ERROR);
		if (ret == FALSE)
			return (FALSE);
		free_tab_str(&data->split);
	}
	if (error(data) == ERROR)
		return (ERROR);
	if (!(print_list(data, data->a)))
		return (FALSE);
	return (TRUE);
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	init_data(&data, argc, argv);
	if ((ret = checker(&data)) == ERROR)
	{
		erase_all(&data);
		return (FALSE);
	}
	else if (ret == FALSE)
		ft_fprintf("KO\n", S_STD);
	else if (ret == TRUE)
		ft_fprintf("OK\n", S_STD);
	erase_all(&data);
	return (FALSE);
}
