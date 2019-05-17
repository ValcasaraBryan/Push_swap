/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/17 14:42:45 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			parsing_push_swap(t_data *data)
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
	return (TRUE);
}

int			operation(t_data *data)
{
	if (!(read_enter(data)))
		return (FALSE);
	print_list(data);
	ft_printf("\n");
	if (data->ope && !ft_strcmp(data->ope->ope, "sa"))
		if (!data->a || !s_ab(&data->a, data->a, data->a->next))
			return (FALSE);
	if (data->ope && !ft_strcmp(data->ope->ope, "sb"))
		if (!data->b || !s_ab(&data->b, data->b, data->b->next))
			return (FALSE);
	if (!(print_list(data)))
		return (FALSE);
	if (!(print_ope(data)))
		return (FALSE);
	return (TRUE);
}

int			checker(t_data *data)
{
	int		ret;
	
	if ((ret = parsing_push_swap(data)) == ERROR)
		return (ERROR);
	else if (ret == FALSE)
		return (FALSE);
	if (operation(data) == FALSE)
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
		ft_printf("KO\n");
	else if (ret == TRUE)
		ft_printf("OK\n");
	erase_all(&data);
	return (FALSE);
}
