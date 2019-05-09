/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/09 22:42:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_arg(t_data *data)
{
	(void)data;
	ft_printf(MSG_U, OPTION_);
	exit (FALSE);
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
	data->option++;
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

int		pars_option(t_data *data)
{
	int	i;
	int	(**fonction)(struct s_data *data);

	i = 1;
	if (!(fonction = malloc(sizeof(fonction) * LEN_OPTION)))
		return (FALSE);
	fonction[VERBOSE] = &verbose;
	fonction[HELP] = &print_help;
	fonction[FILE] = &open_file;
	fonction[PATERN] = &print_patern;
	// ft_printf("%s\n", OPTION_[0]);

	if (!ft_strcmp(data->av[data->index] + i, "h"))
		fonction[1](data);
	if (!ft_strcmp(data->av[data->index] + i, "p"))
		fonction[3](data);
	if (!ft_strcmp(data->av[data->index] + i, "v"))
		return (fonction[0](data));
	if (!ft_strcmp(data->av[data->index] + i, "f"))
		if (fonction[2](data))
			return (TRUE);
	ft_printf("checker: illegal option\n");
	error_arg(data);
	return (FALSE);
}

int		pars_arg(t_data *data)
{
	long long	nb;

	if (!data->av)
		return (FALSE);
	nb = ft_atoll(data->av[data->index]);
	if (nb == 0)
	{
		if (*data->av[data->index] != '-' && !ft_str_is_digit(data->av[data->index]))
			return (FALSE);
		else if (*data->av[data->index] == '-')
			if (!(pars_option(data)))
				return (FALSE);
	}
	return (TRUE);
}

int			checker(int ac, char **av)
{
	t_data	data;
	t_val	*head;
	data.index = 0;
	data.tab = NULL;
	data.len = ac;
	data.av = av;
	data.fd = -1;
	data.option = 0;
	if (data.len <= 1)
		return (FALSE);
	if (!(data.tab = intsplit(av[1], ' ')))
		return (FALSE);
	data.len = ac - 2;
	data.index = -1;
	head = data.tab->prev;
	while (data.tab->next)
	{
		if (data.tab == head)
			break ;
		ft_printf("%14p <-- %14p --> %14p\n", data.tab->prev, data.tab, data.tab->next);
		data.tab = data.tab->next;
	}
		ft_printf("%14p <-- %14p --> %14p\n", data.tab->prev, data.tab, data.tab->next);
			ft_printf("\n");

	// while (++data.index < data.len)
	// {
		// if (pars_arg(&data) && data.tab[data.index] && data.option == 0)
			// ft_printf("%s\n", data.tab[data.index]);
		// else
		// {
			// if (data.tab != av)
				// free_tab_str(&data.tab);
			// return (FALSE);
		// }
	// }
	// if (data.tab != av)
		// free_tab_str(&data.tab);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	if (!(checker(argc, argv)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (FALSE);
}