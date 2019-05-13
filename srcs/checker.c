/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/13 22:17:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_str_is_number(char *str)
{
	int		neg;

	if (!str)
		return (0);
	neg = 0;
	if (str[neg] == '-')
		neg++;
	if (ft_str_is_digit(&str[neg]))
		return (1);
	else
		return (0);
}

int			ft_number_ok(char *str)
{
	if (ft_str_is_number(str) && ft_str_is_int(str))
		return (1);
	else
		return (0);
}

int		error_val(t_data *data, int val)
{
	free_tab_str(&SPLIT);
	ft_fprintf(MSG_ERR, S_ERR);
	// while (1);
	return (val);
}

int		error_arg(t_data *data, int val)
{
	free_tab_str(&SPLIT);
	ft_fprintf(MSG_I, S_ERR);
	ft_fprintf(MSG_U, S_ERR, OPTION_);
	// while (1);
	return (val);
}

int		print_help(t_data *data)
{
	ft_fprintf(MESSAGE_H, S_ERR, OPTION_);
	free_tab_str(&data->split);
	// while (1);
	return (FALSE);
}


int		print_pattern(t_data *data)
{
	ft_fprintf("./checker ", S_ERR);
	print_patern_one(data);
	ft_fprintf("\n", S_ERR);
	ft_fprintf("./checker \"", S_ERR);
	print_patern_one(data);
	ft_fprintf("\"\n", S_ERR);
	print_patern_three(data);
	free_tab_str(&data->split);
	// while (1);
	return (FALSE);
}

void	print_arg(char *str, int val)
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

int		check_other_arg(t_data *data, int i)
{
	while (data->av[i])
		if (ft_number_ok(data->av[i++]))
			return (1);
	return (0);
}

int		check_arg(t_data *data)
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

void	print_patern_one(t_data *data)
{
	int	i;

	i = 0;
	if (i < data->len && check_arg(data))
		while (++i < data->len)
			print_arg(data->av[i], check_other_arg(data, i + 1));
	else
		ft_fprintf("1 2 3 4", S_ERR);
}

int		verbose(t_data *data)
{
	(void)data;
	// data->index++;// v
	// FLAG_O++;
	return (TRUE);
}

void	print_patern_three(t_data *data)
{
	(void)data;
	ft_fprintf(MSG_PA, S_ERR);
}

int		call_help(t_data *data)
{
	if (FLAG_O[HELP])
		return (print_help(data));
	else if (FLAG_O[PATTERN])
		return (print_pattern(data));
	return (TRUE);
}

int		pars_option(t_data *data, char *tab)
{
	int	j;

	j = 0;
	if (tab[j] == '-' && !ft_number_ok(tab))
	{
		while (tab[++j])
		{
			if (params(tab[j], OPTION_) == 0)
				return (ERROR);
			else
				FLAG_O[ft_strnchr(OPTION_, tab[j], LEN_OPTION)] = 1;
		}
		return (TRUE);
	}
	return (FALSE);
}

int		pars(t_data *data)
{
	data->I = -1;
	while (++data->I < data->len_split && FLAG_S == FALSE)
	{
		if (data->split[data->I][0] == '-'
			&& params(SPLIT[data->I][1], OPTION_)
				&& !ft_number_ok(SPLIT[data->I]))
		{
			if (FLAG_O[ft_strnchr(OPTION_, SPLIT[data->I][1], LEN_OPTION)])
			{
				ft_printf(MSG_I);
				return (ERROR);
			}
			FLAG_O[ft_strnchr(OPTION_, SPLIT[data->I][1], LEN_OPTION)] = 1;
			FLAG_V = FLAG_O[VERBOSE] ? TRUE : FLAG_V;
		}
		else if (FLAG_O[EDIT] == FALSE)
			FLAG_S = TRUE;
	}
	return (TRUE);
}

void		print_list(t_data *data, t_val *head)
{
	head = data->tab;
	if (!head)
		return ;
	if (head->prev)
		head->prev->next = NULL;
	while (head->next)
	{
		ft_fprintf("%14p <-- %14p --> %14p | %d\n", S_STD, head->prev, head, head->next, head->val);
		head = head->next;
	}
	ft_fprintf("%14p <-- %14p                    | %d\n", S_STD, head->prev, head, head->val);
}

void		init_data(t_data *data, int ac, char **av)
{
	int		i;
	data->av = av;
	data->split = NULL;
	data->flag = FALSE;
	data->flag_file = FALSE;
	data->flag_edit = FALSE;
	data->flag_verbose = FALSE;
	data->index = TRUE;
	data->index_split = -1;
	data->len = ac;
	data->len_split = FALSE;
	data->tab = NULL;
	data->fd = -1;
	data->output = -1;

	i = -1;
	while (++i < LEN_OPTION)
		FLAG_O[i] = FALSE;
}

int			len_arg_number(char **str)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[++i])
		if (ft_number_ok(str[i]))
			len++;
	return (len);
}

int			split_file(t_data *data, char *line)
{
	char	**tab;
	int		i;

	if (!(tab = ft_strsplit(line, ' ')))
		return (ERROR);
	i = -1;
	while (tab[++i])
	{
		if (ft_number_ok(tab[i]))
			data->tab = intsplit(data->tab, tab[i], ' ');
		else
		{
			ft_fprintf(MSG_ERR, S_ERR);
			free_tab_str(&tab);
			return (ERROR);
		}
	}
	free_tab_str(&tab);
	return (TRUE);
}

int			take_file(t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(data->fd, &line)) > 0)
	{
		if (split_file(data, line) == ERROR)
		{
			free(line);
			line = NULL;
			return (ERROR);
		}
		free(line);
		line = NULL;
	}
	FLAG_F = FALSE;
	return (TRUE);
}

int			open_file(t_data *data)
{
	char	*buf;

	buf = NULL;
	if (data->I + 1 < data->len_split && FLAG_F == FALSE)
	{
		buf = SPLIT[data->I++ + 1];
		FLAG_F = TRUE;
	}
	else if (data->index + 1 < data->len && FLAG_F == FALSE)
	{
		FLAG_F = TRUE;
		return (TRUE);
	}
	else if (FLAG_F == FALSE)
	{
		ft_fprintf(F_NMIS, S_ERR);
		return (ERROR);
	}
	else if (FLAG_F == TRUE)
		buf = SPLIT[data->I];
	else
		return (ERROR);
	if ((data->fd = open(buf, O_RDONLY)) == -1)
	{
		ft_fprintf(F_DOES, S_ERR);
		return (ERROR);
	}
	if (take_file(data) == ERROR)
	{
		erase_list(&data->tab);
		close(data->fd);
		return (ERROR);
	}
	close(data->fd);
	return (TRUE);
}

int			open_edit(t_data *data)
{
	char	*buf;

	buf = NULL;
	if (data->I + 1 < data->len_split && FLAG_E == FALSE)
	{
		buf = SPLIT[data->I++ + 1];
		FLAG_E = TRUE;
	}
	else if (data->index + 1 < data->len && FLAG_E == FALSE)
	{
		FLAG_E = TRUE;
		return (TRUE);
	}
	else if (FLAG_E == FALSE)
	{
		ft_fprintf(E_NMIS, S_ERR);
		return (ERROR);
	}
	else
		buf = SPLIT[data->I];
	if ((data->output = open(buf, O_RDWR
		| O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH)) == -1)
	{
		ft_fprintf(E_FERR, S_ERR);
		return (ERROR);
	}
	FLAG_O[EDIT] = FALSE;
	FLAG_E = ERROR;
	return (TRUE);
}

int			take_arguments(t_data *data)
{
	data->I = -1;
	while (++data->I < data->len_split)
	{
		// printf("%-10s - S[%3d] - F[%3d] - E[%3d] - V[%3d]\n", SPLIT[data->I], FLAG_S, FLAG_F, FLAG_E, FLAG_V);
		if (ft_number_ok(SPLIT[data->I]))
			data->tab = intsplit(data->tab, SPLIT[data->I], ' ');
		else if ((params(FILE_OP, SPLIT[data->I]) || FLAG_F == TRUE) && FLAG_O[EDIT] != TRUE)
		{
			if (open_file(data) == ERROR)
				return (ERROR);
		}
		else if (FLAG_O[EDIT])
		{
			if (open_edit(data) == ERROR)
				return (ERROR);
		}
		else if (FLAG_S == TRUE)
			return (error_arg(data, ERROR));
	}
	return (TRUE);
}

int			checker(int ac, char **av)
{
	t_data	data;

	init_data(&data, ac, av);
	if (data.len <= 1)
		return (FALSE);
	while (data.index < data.len)
	{
		// ft_printf("%s\n", data.av[data.index]);
		if (!(data.split = ft_strsplit(data.av[data.index], ' ')))
			return (ERROR);
		data.len_split = ft_len_tab_str(data.split);
		if (pars(&data) == ERROR)
			return (ERROR);
		if (!(call_help(&data)))
			return (MSG);
		if (take_arguments(&data) == ERROR)
		{
			erase_list(&data.tab);
			return (ERROR);
		}
		free_tab_str(&data.split);
		data.index++;
	}
	print_list(&data, data.tab);
	erase_list(&data.tab);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	int	ret;
	if ((ret = checker(argc, argv)) == ERROR)
		return (FALSE);
	else if (ret == FALSE)
		ft_fprintf("KO\n", S_STD);
	else if (ret == TRUE)
		ft_fprintf("OK\n", S_STD);
	return (FALSE);
}