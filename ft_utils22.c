#include "minishell.h"

void	parsing_dol(t_struct *d, t_list *l)
{
	d->l.i = 0;
	d->l.tmp = malloc(1);
	d->l.tmp[0] = '\0';
	while (d->l.line[d->l.i])
	{
		parsing_dol_2(d, l);
		d->l.i++;
	}
	free_str(d->l.line);
	d->l.line = ft_strdup(d->l.tmp);
	free_str(d->l.tmp);
}

char	*cat_char_malloc(char *res, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	tmp = malloc(ft_strlen(res) + 2);
	while (res[++i])
		tmp[i] = res[i];
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free_str(res);
	return (tmp);
}
