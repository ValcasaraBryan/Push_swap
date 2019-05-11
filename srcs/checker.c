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

int		error_val(t_data *data, int val, char ***tab)
{
	(void)data;
	free_tab_str(tab);
	ft_fprintf(MSG_ERR, S_ERR);
	erase_data(data);
	return (val);
}

int		error_arg(t_data *data, int val, char ***tab)
{
	(void)data;
	free_tab_str(tab);
	ft_fprintf(MSG_I, S_ERR);
	ft_fprintf(MSG_U, S_ERR, OPTION_);
	erase_data(data);
	return (val);
}

int		print_help(t_data *data)
{
	ft_fprintf(MESSAGE_H, S_ERR, OPTION_);
	erase_data(data);
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
		if (ft_str_is_int(tab[i]))
			len++;
	i = -1;
	while (tab[++i])
		if (ft_str_is_int(tab[i]))
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
		if (ft_str_is_int(data->av[i++]))
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
			if (ft_str_is_int(tab[j++]))
				arg++;
		free_tab_str(&tab);
	}
	return ((arg < 2) ? 0 : 1);
}

void	print_patern_one(t_data *data)
{
	int	i;

	i = data->index - 1;
	if (i < data->len && check_arg(data))
		while (++i < data->len)
			print_arg(data->av[i], check_other_arg(data, i + 1));
	else
		ft_fprintf("1 2 3 4", S_ERR);
}

int		open_file(t_data *data)
{
	if (data->index + 1 == data->len - 1)
	{
		if ((data->fd = open(data->av[data->index + 1], O_RDWR)) <= -1)
			ft_fprintf("Wrong file\n", S_ERR);
		else
		{
			data->index++;
			return (TRUE);
		}
	}
	else if (data->index + 1 < data->len - 1)
		ft_fprintf("Too many arguments\n", S_ERR);
	else
		ft_fprintf("Missing file name\n", S_ERR);
	return (FALSE);
}

int		verbose(t_data *data)
{
	data->index++;// v
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

void	pars_val_file(t_data *data, char tab, int *file)
{
	(*file) = (data->option[FILE]
		&& !*file && params(tab, &OPTION_[FILE]) == 0) ? 1 : 0;
}

int		pars_option(t_data *data, char *tab)
{
	int	j;

	j = 0;
	if (tab[j] == '-')
		while (tab[++j])
		{
			if (params(tab[j], OPTION_) == 0)
				return (ERROR);
			else
				data->option[ft_strnchr(OPTION_, tab[j], LEN_OPTION)] = 1;
		}
	return (TRUE);
}

int		file_option(t_data *data, char *tab, int *file)
{
	int	j;

	j = 0;
	if (tab[j] != '-' && !*file)
	{
		if (!(ft_str_is_int(tab)))
			return (ERROR);
	}
	else
		pars_val_file(data, tab[j], file);
	return (TRUE);
}

int		pars(t_data *data, int index, int *file)
{
	int		i;
	char	**tab;

	if (!data->av)
		return (ERROR);
	if (!(tab = ft_strsplit(data->av[index], ' ')))
		return (ERROR);
	i = -1;
	while (tab[++i])
	{
		if (pars_option(data, tab[i]) == ERROR)
			return (error_arg(data, ERROR, &tab));
		if (file_option(data, tab[i], file) == ERROR)
			return (error_val(data, ERROR, &tab));
	}
	free_tab_str(&tab);
	return (TRUE);
}

void		print_list(t_data *data, t_val *head)
{
	head = data->tab;
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
	data->index = 1;
	data->tab = NULL;
	data->len = ac;
	data->av = av;
	data->fd = -1;
	data->arg = NULL;
	i = -1;
	while (++i < LEN_OPTION)
		data->option[i] = 0;
}

int			check_val(t_data *data)
{
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (++i < data->len)
		if (pars(data, i, &flag) == ERROR)
			return (ERROR);
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
	else if (ret == FALSE)
	{
		ft_printf("open\n");
	}
	// int i = -1;
	// while (++i < LEN_OPTION)
		// ft_printf("\t%d\n", data.option[i]);
	// while (data.index < ac)
	// {
		// ft_fprintf("%s\n", S_STD, data.av[data.index++]);
	// }
	// if (!(data.tab = intsplit(data.av[data.index], ' ')))
		// return (FALSE);
	// data.len = ac - 2;
	// data.index = -1;
	// print_list(&data, data.tab);

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
	else
		return (FALSE);
}