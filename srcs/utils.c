/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:31:02 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 18:47:43 by brvalcas         ###   ########.fr       */
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
	data->index = 0;
	data->index_split = -1;
	data->len = ac;
	data->len_split = FALSE;
	data->ope = NULL;
	data->a = NULL;
	data->b = NULL;
	data->fd = -1;
	data->output = -1;
	data->edit = NULL;
	i = -1;
	while (++i < LEN_OPTION)
		FLAG_O[i] = FALSE;
	init_ope(data);
}

int			print_list(t_data *data)
{
	t_val	*head;
	t_val	*tmp;

	if (!data->a->next)
	{
		ft_fprintf("%d\n", S_STD, data->a->val);
		return (TRUE);
	}
	head = data->a;
	tmp = data->a->prev;
	while (head->next)
	{
		// ft_fprintf("%14p <-- %14p --> %14p | %d\n",
			// S_STD, head->prev, head, head->next, head->val);
		ft_fprintf("%d\n", S_STD, head->val);
		if (head == tmp)
			break ;
		head = head->next;
	}
	// ft_fprintf("%14p <-- %14p                    | %d\n",
		// S_STD, head->prev, head, head->val);
		// ft_fprintf("%d\n", S_STD, head->val);
	return (TRUE);
}

int			print_ope(t_data *data)
{
	t_ope	*tmp;
	
	tmp = data->ope;
	if (!tmp)
		return (0);
	while (tmp)
	{
		ft_printf("%s\n", tmp->ope);
		tmp = tmp->next;
	}
	return (1);
}

int			verbose(t_data *data)
{
	(void)data;
	return (TRUE);
}

void		erase_all(t_data *data)
{
	erase_list(&data->a);
	erase_list(&data->b);
	erase_ope(data);
	free_tab_str(&data->split);
	if (data->edit)
	{
		free(data->edit);
		data->edit = NULL;
	}
}
