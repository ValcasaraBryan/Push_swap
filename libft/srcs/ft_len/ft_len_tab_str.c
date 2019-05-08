int			ft_len_tab_str(char **tab)
{
	int		i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}
