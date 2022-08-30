#include "minishell.h"

void	parsing_all(t_struct *d, t_list *l)
{
	char	*line;

	line = NULL;
	parsing_dol(d, l);
	del_space_start(d);
	del_space_end(d);
	cpy_cmd(d);
	d->l.arg = ft_split(d->l.line, ' ');
	if (!(is_chevron(d)))
		quote_arg(d);
	d->l.cmd = del_quote(d, d->l.cmd);
	if (is_chevron(d))
		parsing_all_2(d, line);
}

void	parsing_all_2(t_struct *d, char *line)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	fill_chevron(d);
	che_to_tab(d);
	chev_count(d);
	del_space_start_che(d);
	del_space_end_che(d);
	while (d->l.line[i] && d->l.line[i] != '>' && d->l.line[i] != '<')
		i++;
	line = ft_substr(d->l.line, 0, i - 1);
	d->l.arg_chev = ft_split(line, ' ');
	free_str(line);
	while (d->l.arg_chev[++k])
		d->l.arg_chev[k] = del_quote(d, d->l.arg_chev[k]);
}
