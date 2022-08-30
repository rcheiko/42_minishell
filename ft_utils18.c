#include "minishell.h"

void	del_space_start_echo(t_struct *d)
{
	char	*str;

	str = malloc(sizeof (char) * (ft_len_wspa(d->l.echo) + 1));
	ft_strcpy_wspa(d->l.echo, str);
	free(d->l.echo);
	d->l.echo = NULL;
	d->l.echo = str;
}

void	parsing_dol_7(t_struct *d, t_list *l)
{
	d->l.i++;
	while (d->l.line[d->l.i] && d->l.line[d->l.i] != '$'
		&& d->l.line[d->l.i] != ' ' && d->l.line[d->l.i] != '"')
	{
		d->l.c++;
		d->l.i++;
	}
	d->l.sub = ft_substr(d->l.line, d->l.i - d->l.c, d->l.c);
	d->l.env = search_env(l, d->l.sub);
	if (d->l.env != NULL)
	{
		d->l.tmp2 = ft_strjoin(d->l.tmp, d->l.env);
		free_str(d->l.tmp);
		d->l.tmp = d->l.tmp2;
	}
	free_str(d->l.env);
	free_str(d->l.sub);
}
