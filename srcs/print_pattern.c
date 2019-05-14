/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:23:09 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/14 16:25:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			print_pattern(t_data *data)
{
	ft_fprintf("./checker -e [edit_name] ", S_ERR);
	print_patern_one(data);
	ft_fprintf(" \"", S_ERR);
	print_patern_one(data);
	ft_fprintf("\" ", S_ERR);
	print_patern_three(data);
	free_tab_str(&data->split);
	return (ERROR);
}

void		print_patern_one(t_data *data)
{
	int		i;

	i = 0;
	if (i < data->len && check_arg(data))
		while (++i < data->len)
			print_arg(data->av[i], check_other_arg(data, i + 1));
	else
		ft_fprintf("1 2 3 4", S_ERR);
}

int			check_arg(t_data *data)
{
	char	**tab;
	int		i;
	int		j;
	int		arg;

	arg = 0;
	i = 0;
	while (++i < data->len)
	{
		if (!(tab = ft_strsplit(data->av[i], ' ')))
			return (0);
		j = 0;
		while (tab[j])
			if (ft_number_ok(tab[j++]))
				arg++;
		free_tab_str(&tab);
	}
	return ((arg < 2) ? 0 : 1);
}

int			check_other_arg(t_data *data, int i)
{
	while (data->av[i])
		if (ft_number_ok(data->av[i++]))
			return (1);
	return (0);
}

void		print_patern_three(t_data *data)
{
	(void)data;
	ft_fprintf(MSG_PA, S_ERR);
}
