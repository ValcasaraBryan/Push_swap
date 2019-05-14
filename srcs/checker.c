/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/14 15:57:00 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_str_is_number(char *str)
{
	int		neg;

	if (!str)
		return (0);
	neg = 0;
	if (str[neg] == '-' || str[neg] == '+')
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

int			error_val(t_data *data)
{
	free_tab_str(&SPLIT);
	ft_fprintf(MSG_ERR, S_ERR);
	return (ERROR);
}

int			error_arg(t_data *data)
{
	free_tab_str(&SPLIT);
	ft_fprintf(MSG_I, S_ERR);
	ft_fprintf(MSG_U, S_ERR, OPTION_);
	return (ERROR);
}

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

int			check_other_arg(t_data *data, int i)
{
	while (data->av[i])
		if (ft_number_ok(data->av[i++]))
			return (1);
	return (0);
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

int			verbose(t_data *data)
{
	(void)data;
	return (TRUE);
}

void		print_patern_three(t_data *data)
{
	(void)data;
	ft_fprintf(MSG_PA, S_ERR);
}

int			call_help(t_data *data)
{
	if (FLAG_O[HELP])
		return (print_help(data));
	else if (FLAG_O[PATTERN])
		return (print_pattern(data));
	return (TRUE);
}

int			ft_is_option(char *str, char *option)
{
	int		i;

	i = 0;
	if (ft_number_ok(str))
		return (FALSE);
	while (str[++i])
		if (params(str[i], option) == FALSE)
			return (FALSE);
	return (i > 1 ? TRUE : FALSE);
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
		if (FLAG_O[HELP])
			return (print_msg(data, FLAG_O[HELP]));
		if (FLAG_O[PATTERN])
			return (print_msg(data, FLAG_O[PATTERN]));
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
			flag = TRUE;
		else
			return (error_arg(data));
	}
	return (TRUE);
}

int			check_option(t_data *data)
{
	if (ft_is_option(SPLIT[data->I], OPTION_) && FLAG_O[EDIT] == FALSE)
	{
		if (active_option(data, 0, 0) == ERROR)
			return (ERROR);
	}
	else if (FLAG_O[EDIT] == TRUE)
	{
		FLAG_O[EDIT] = FALSE;
		if (open_edit(data) == ERROR)
			return (ERROR);
	}
	else
		OPT = FALSE;
	return (TRUE);
}

int			check_no_option(t_data *data)
{
	if (!ft_is_option(SPLIT[data->I], OPTION_)
		&& ft_is_option(SPLIT[data->I], FILE_OP) && FILE == FALSE)
	{
		if (active_no_option(data, 0) == ERROR)
			return (ERROR);
		FILE = TRUE;
	}
	else if (FILE == TRUE)
	{
		if (open_file(data) == ERROR)
			return (ERROR);
		FILE = FALSE;
	}
	else if (ft_number_ok(SPLIT[data->I]))
		data->tab = intsplit(data->tab, SPLIT[data->I], ' ');
	else
		return (error_arg(data));
	return (TRUE);
}

int			pars(t_data *data)
{
	data->I = -1;
	while (++data->I < data->len_split)
	{
		if (OPT == TRUE)
			if (check_option(data) == ERROR)
				return (ERROR);
		if (OPT == FALSE)
			if (check_no_option(data) == ERROR)
				return (ERROR);
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
		ft_fprintf("%14p <-- %14p --> %14p | %d\n",
			S_STD, head->prev, head, head->next, head->val);
		head = head->next;
	}
	ft_fprintf("%14p <-- %14p                    | %d\n",
		S_STD, head->prev, head, head->val);
}

void		init_data(t_data *data, int ac, char **av)
{
	int		i;

	data->av = av;
	data->split = NULL;
	data->no_file = FALSE;
	data->no_option = TRUE;
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
	return (TRUE);
}

int			open_file(t_data *data)
{
	if ((data->fd = open(SPLIT[data->I], O_RDONLY)) == -1)
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

int			error_file(t_data *data)
{
	(void)data;
	ft_fprintf(F_NMIS, S_ERR);
	return (ERROR);
}

int			error_edit(t_data *data)
{
	(void)data;
	ft_fprintf(E_NMIS, S_ERR);
	return (ERROR);
}

int			open_edit(t_data *data)
{
	if ((data->output = open(SPLIT[data->I], O_RDWR
		| O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH)) == -1)
	{
		ft_fprintf(E_FERR, S_ERR);
		return (ERROR);
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
		if (!(data.split = ft_strsplit(data.av[data.index], ' ')))
			return (ERROR);
		if (!(data.len_split = ft_len_tab_str(data.split)))
			return (error_arg(&data));
		if (pars(&data) == ERROR)
			return (ERROR);
		free_tab_str(&data.split);
		data.index++;
	}
	if (data.option[EDIT] == TRUE)
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
