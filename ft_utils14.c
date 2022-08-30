#include "minishell.h"

int	len_line_fdol(t_struct *d)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (cpt != 1 && d->l.line[i])
	{
		if (d->l.line[i] == '$')
			cpt++;
		i++;
	}
	while (d->l.line[i]
		&& ((d->l.line[i] >= '0' && d->l.line[i] <= '9')
			|| (d->l.line[i] >= 'a' && d->l.line[i] <= 'z')
			|| (d->l.line[i] >= 'A' && d->l.line[i] <= 'Z')))
		i++;
	if (d->l.line[i + 1] == 0)
		i++;
	return (i);
}

int	len_line_dol(t_struct *d)
{
	int	i;
	int	cpt;
	int	total;

	i = 0;
	cpt = 0;
	total = 0;
	while (cpt != 1 && d->l.line[i])
	{
		if (d->l.line[i] == '$')
			cpt++;
		i++;
	}
	while (d->l.line[i]
		&& ((d->l.line[i] >= '0' && d->l.line[i] <= '9')
			|| (d->l.line[i] >= 'a' && d->l.line[i] <= 'z')
			|| (d->l.line[i] >= 'A' && d->l.line[i] <= 'Z')))
	{
		i++;
		total++;
	}
	return (total + 1);
}

int	mal_del_quote(t_struct *d, char *str)
{
	int	y;
	int	t;

	d->l.i = -1;
	y = 0;
	t = ft_strlen(str) - 1;
	if (str[0] == '\'' || str[t] == '\'')
	{
		while (str[++d->l.i])
		{
			if (str[d->l.i] == '\'')
				y--;
			y++;
		}
	}
	else if (str[0] == '"' || str[t] == '"')
	{
		while (str[++d->l.i])
		{
			if (str[d->l.i] == '\'')
				y--;
			y++;
		}
	}
	return (y);
}

char	*del_quote(t_struct *d, char *str)
{
	int		i;
	int		y;
	int		t;
	char	*res;

	i = -1;
	y = mal_del_quote(d, str);
	t = ft_strlen(str) - 1;
	if (y == 0)
		return (str);
	res = malloc(sizeof (char) * (y + 1));
	y = 0;
	if (str[0] == '\'' || str[t] == '\'')
		while (str[++i])
			if (str[i] != '\'')
				res[y++] = str[i];
	if (str[0] == '"' || str[t] == '"')
		while (str[++i])
			if (str[i] != '"')
				res[y++] = str[i];
	res[y] = '\0';
	free_str(str);
	return (res);
}

void	quote_arg(t_struct *d)
{
	int		k;
	char	*tmp;

	k = 0;
	while (d->l.arg[k])
	{
		tmp = del_quote(d, d->l.arg[k]);
		d->l.arg[k] = NULL;
		d->l.arg[k] = tmp;
		k++;
	}
}
