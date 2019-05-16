/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:31:02 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 14:28:58 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_data(t_data *data, int ac, char **av)
{
	int		i;

	data->av = av;
	data->split = NULL;
	data->no_file = FALSE;
	data->no_edit = FALSE;
	data->no_option = TRUE;
	data->index = TRUE;
	data->index_split = -1;
	data->len = ac;
	data->len_split = FALSE;
	data->tab = NULL;
	data->fd = -1;
	data->output = -1;
	data->edit = NULL;
	i = -1;
	while (++i < LEN_OPTION)
		FLAG_O[i] = FALSE;
}

int			print_list(t_data *data, t_val *head)
{
	head = data->tab;
	if (!head)
		return (FALSE);
	if (head->prev)
		head->prev->next = NULL;
	while (head->next)
	{
		ft_fprintf("%14p <-- %14p --> %14p | %d\n",
			S_STD, head->prev, head, head->next, head->val);
		head = head->next;
	}
	ft_fprintf("%14p <-- %14p                    | %d\n",
		S_STD, head->prev, head, head->val);
	return (TRUE);
}

int			verbose(t_data *data)
{
	(void)data;
	return (TRUE);
}

void		erase_all(t_data *data)
{
	erase_list(&data->tab);
	free_tab_str(&data->split);
	if (data->edit)
	{
		free(data->edit);
		data->edit = NULL;
	}
}