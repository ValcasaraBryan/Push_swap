/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:27:45 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/14 16:28:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			print_msg(t_data *data, int val)
{
	if (val == FLAG_O[HELP])
		return (print_help(data));
	else if (val == FLAG_O[PATTERN])
		return (print_pattern(data));
	else
		return (FALSE);
}

int			print_help(t_data *data)
{
	ft_fprintf(MESSAGE_H, S_ERR, OPTION_);
	free_tab_str(&data->split);
	return (ERROR);
}

void		print_arg(char *str, int val)
{
	char	**tab;
	int		len;
	int		i;

	if (!(tab = ft_strsplit(str, ' ')))
		return ;
	i = -1;
	len = 0;
	while (tab[++i])
		if (ft_number_ok(tab[i]))
			len++;
	i = -1;
	while (tab[++i])
		if (ft_number_ok(tab[i]))
		{
			ft_fprintf("%s", S_ERR, tab[i]);
			if (val || i < len - 1)
				ft_fprintf(" ", S_ERR);
		}
	free_tab_str(&tab);
}
