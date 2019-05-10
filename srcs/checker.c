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

void	error_arg(t_data *data)
{
	(void)data;
	ft_printf(MSG_I);
	ft_printf(MSG_U, OPTION_);
	erase_data(data);
}

void	print_arg(char *str, int val)
{
	char	**tab;
	int		len;
	int		i;

	if (!(tab = ft_strsplit(str, ' ')))
		return ;
	i = -1;
	len = ft_len_tab_str(tab);
	while (tab[++i])
		if (ft_str_is_int(tab[i]))
		{
			ft_printf("%s", tab[i]);
			if (val || i < len - 1)
				ft_printf(" ");
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

void	print_patern_one(t_data *data)
{
	int	i;

	i = data->index - 1;
	ft_printf("./checker ");
	if (i < data->len && data->len > 2)
		while (++i < data->len)
			print_arg(data->av[i], check_other_arg(data, i + 1));
	else
		ft_printf("1 2 3 4");
	ft_printf("\n");
}

void	print_patern_two(t_data *data)
{
	int	i;

	i = data->index - 1;
	ft_printf("./checker \"");
	if (i < data->len && data->len > 2)
		while (++i < data->len)
			print_arg(data->av[i], check_other_arg(data, i + 1));
	else
		ft_printf("1 2 3 4");
	ft_printf("\"\n");
}

int		open_file(t_data *data)
{
	if (data->index + 1 == data->len - 1)
	{
		if ((data->fd = open(data->av[data->index + 1], O_RDWR)) <= -1)
			ft_printf("Wrong file\n");
		else
		{
			data->index++;
			return (TRUE);
		}
	}
	else if (data->index + 1 < data->len - 1)
		ft_printf("Too many arguments\n");
	else
		ft_printf("Missing file name\n");
	error_arg(data);
	return (FALSE);
}

int		print_help(t_data *data)
{
	ft_printf(MESSAGE_H, OPTION_);
	erase_data(data);
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

int		print_pattern(t_data *data)
{
	print_patern_one(data);
	print_patern_two(data);
	print_patern_three(data);
	erase_data(data);
	return (FALSE);
}

void	print_patern_three(t_data *data)
{
	(void)data;
	ft_printf(MSG_PA);
}

int		pars_salut(t_data *data)
{
	if (data->option[HELP])
		return (print_help(data));
	else if (data->option[PATTERN])
		return (print_pattern(data));
	return (TRUE);
}

int		pars_option(t_data *data)
{
	int		i;

	if (!data->av)
		return (ERROR);
	i = 1;
	if (data->av[data->index][0] != '-')
		return (FALSE);
	while (data->av[data->index][i] && data->av[data->index][i] != ' '
		&& data->av[data->index][i] != '\t')
		i++;
	if (!(data->arg = ft_strndup(data->av[data->index] + 1, i - 1)))
		return (ERROR);
	data->av[data->index] += i + 1;
	// ft_printf("%s\n", data->av[data->index]);
	i = -1;
	while (data->arg[++i])
		if (params(data->arg[i], OPTION_) == 0)
			return (ERROR);
		else
			data->option[ft_strnchr(OPTION_, data->arg[i], LEN_OPTION)] = 1;
	return (TRUE);
}

void		print_list(t_data *data, t_val *head)
{
	head = data->tab;
	if (head->prev)
		head->prev->next = NULL;
	while (head->next)
	{
		ft_printf("%14p <-- %14p --> %14p | %d\n", head->prev, head, head->next, head->val);
		head = head->next;
	}
	ft_printf("%14p <-- %14p                    | %d\n", head->prev, head, head->val);
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

int			checker(int ac, char **av)
{
	t_data	data;
	int		ret;

	init_data(&data, ac, av);
	if (data.len <= 1)
		return (FALSE);
	while (data.index < ac)
	{
		if ((ret = pars_option(&data)) == FALSE)
			break ;
		else if (ret == TRUE)
		{
			if (!(pars_salut(&data)))
				return (MSG);
		}
		else if (ret == ERROR)
		{
			error_arg(&data);
			return (ERROR);
		}
		data.index++;
	}
	while (data.index < ac)
	{
		ft_printf("%s\n", data.av[data.index++]);
	}
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
		ft_printf("KO\n");
	else if (ret == TRUE)
		ft_printf("OK\n");
	else
		return (FALSE);
}