/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 19:40:34 by brvalcas         ###   ########.fr       */
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

int		error_val(t_data *data, int val, char ***tab)
{
	(void)data;
	free_tab_str(tab);
	ft_fprintf(MSG_ERR, S_ERR);
	erase_data(data);
	// while (1);
	return (val);
}

int		error_arg(t_data *data, int val, char ***tab)
{
	(void)data;
	free_tab_str(tab);
	ft_fprintf(MSG_I, S_ERR);
	ft_fprintf(MSG_U, S_ERR, OPTION_);
	erase_data(data);
	// while (1);
	return (val);
}

int		print_help(t_data *data)
{
	ft_fprintf(MESSAGE_H, S_ERR, OPTION_);
	erase_data(data);
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
	erase_data(data);
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
	// data->option++;
	return (TRUE);
}

void	erase_data(t_data *data)
{
	free(data->arg);
	data->arg = NULL;
}

void	print_patern_three(t_data *data)
{
	(void)data;
	ft_fprintf(MSG_PA, S_ERR);
}

int		call_help(t_data *data)
{
	if (data->option[HELP])
		return (print_help(data));
	else if (data->option[PATTERN])
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
				data->option[ft_strnchr(OPTION_, tab[j], LEN_OPTION)] = 1;
		}
		return (TRUE);
	}
	return (FALSE);
}

int		file_option(t_data *data, char *tab, int option)
{
	if (option == TRUE && params(OPTION_[FILE], tab)
		&& data->option[FILE] && !data->file)
		data->file = 1;
	else if (option == FALSE && data->file)
		data->file = 0;
	else if (option == FALSE && !data->file)
		if (!(ft_number_ok(tab)))
			return (ERROR);
	return (TRUE);
}

int		pars(t_data *data, int index)
{
	int		i;
	int		ret;
	char	**tab;

	if (!data->av)
		return (ERROR);
	if (!(tab = ft_strsplit(data->av[index], ' ')))
		return (ERROR);
	i = -1;
	while (tab[++i])
	{
		if ((ret = pars_option(data, tab[i])) == ERROR)
			return (error_arg(data, ERROR, &tab));
		if (file_option(data, tab[i], ret) == ERROR)
			return (error_val(data, ERROR, &tab));
	}
	free_tab_str(&tab);
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
	data->tab = NULL;
	data->len = ac;
	data->av = av;
	data->fd = -1;
	data->file = 0;
	data->arg = NULL;
	i = -1;
	while (++i < LEN_OPTION)
		data->option[i] = 0;
}

int			check_val(t_data *data)
{
	int		i;

	i = 0;
	while (++i < data->len)
		if (pars(data, i) == ERROR)
			return (ERROR);
	return (TRUE);
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

int			open_file(t_data *data, char **split, int *i, int *j)
{
	char	*buf;

	if (*j + 1 < ft_len_tab_str(split))
		buf = split[(*j)++ + 1];
	else if (*i + 1 < data->len)
		buf = data->av[(*i)++ + 1];
	else
	{
		ft_fprintf(F_NMIS, S_ERR);
		return (ERROR);
	}
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

int			take_arguments(t_data *data)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = NULL;
	while (++i < data->len)
	{
		j = -1;
		if (!(split = ft_strsplit(data->av[i], ' ')))
			return (ERROR);
		while (split[++j])
		{
			if (ft_number_ok(split[j]))
				data->tab = intsplit(data->tab, split[j], ' ');
			else
				if (open_file(data, split, &i, &j) == ERROR)
				{
					free_tab_str(&split);
					return (ERROR);
				}
		}
		free_tab_str(&split);
	}
	print_list(data, data->tab);
	return (TRUE);
}

int			checker(int ac, char **av)
{
	t_data	data;
	int		ret;

	init_data(&data, ac, av);
	if (data.len <= 1)
		return (FALSE);
	if ((ret = check_val(&data)) == ERROR)
		return (ERROR);
	if (!(call_help(&data)))
		return (MSG);
	if (take_arguments(&data) == ERROR)
		return (ERROR);
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