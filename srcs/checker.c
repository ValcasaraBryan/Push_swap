/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 17:44:44 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_arg(t_data *data)
{
	(void)data;
	ft_printf(MSG_I);
	ft_printf(MSG_U, OPTION_);
}

void	print_patern_one(t_data *data)
{
	int	i;

	i = data->index;
	ft_printf("./checker ");
	if (i < data->len - 1 && data->len > 3)
		while (++i < data->len)
		{
			ft_printf("%s", data->av[i]);
			if (i < data->len - 1)
				ft_printf(" ");
			else
				ft_printf("\n");
		}
	else
		ft_printf("1 2 3 4\n");
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
	ft_printf("%s", MESSAGE_H);
	ft_printf("\n");
	error_arg(data);
	return (TRUE);
}

int		verbose(t_data *data)
{
	data->index++;// v
	// data->option++;
	return (TRUE);
}

int		print_patern(t_data *data)
{
	print_patern_one(data);
	print_patern_two(data);
	print_patern_three(data);
	error_arg(data);
	return (TRUE);
}

void	print_patern_two(t_data *data)
{
	int	i;

	i = data->index;
	ft_printf("./checker \"");
	if (i < data->len - 1 && data->len > 3)
		while (++i < data->len)
		{
			ft_printf("%s", data->av[i]);
			if (i < data->len - 1)
				ft_printf(" ");
			else
				ft_printf("\"\n");
		}
	else
		ft_printf("1 2 3 4\"\n");
}

void	print_patern_three(t_data *data)
{
	(void)data;
	ft_printf(MSG_PA);
	ft_printf(MSG_PAT);
}

int		pars_salut(t_data *data)
{
	int	(**fonction)(struct s_data *data);

	if (!(fonction = malloc(sizeof(fonction) * LEN_OPTION)))
		return (FALSE);
	fonction[VERBOSE] = &verbose;
	fonction[HELP] = &print_help;
	fonction[FILE] = &open_file;
	fonction[PATERN] = &print_patern;
	// if (!ft_strcmp(data->av[data->index], "h"))
		// fonction[1](data);
	// if (!ft_strcmp(data->av[data->index], "p"))
		// fonction[3](data);
	// if (!ft_strcmp(data->av[data->index], "v"))
		// return (fonction[0](data));
	// if (!ft_strcmp(data->av[data->index], "f"))
		// if (fonction[2](data))
			// return (TRUE);
	ft_printf("checker: illegal option\n");
	error_arg(data);
	return (FALSE);
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
	if ((ret = pars_option(&data)) == FALSE)
	{}
	else if (ret == TRUE)
	{
		ft_printf("%d\n", data.option[0]);
		ft_printf("%d\n", data.option[1]);
		ft_printf("%d\n", data.option[2]);
		ft_printf("%d\n", data.option[3]);
		ft_printf("%d\n", data.option[4]);
		ft_printf("%d\n", data.option[5]);
	}
	else if (ret == ERROR)
	{
		error_arg(&data);
		return (ERROR);
	}

	if (!(data.tab = intsplit(data.av[1], ' ')))
		return (FALSE);
	// data.len = ac - 2;
	// data.index = -1;
	print_list(&data, data.tab);
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
	return (FALSE);
}