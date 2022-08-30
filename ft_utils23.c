#include "minishell.h"

void	parsing_dol_2(t_struct *d, t_list *l)
{
	if (d->l.line[d->l.i] && d->l.line[d->l.i] == '\''
		&& d->l.line[d->l.i + 1])
	{
		d->l.i++;
		while (d->l.line[d->l.i] && d->l.line[d->l.i] != '\'')
		{
			if (d->l.line[d->l.i] == '<' || d->l.line[d->l.i] == '>')
				d->l.chev_echo = 1;
			d->l.tmp = cat_char_malloc(d->l.tmp, d->l.line[d->l.i++]);
		}
	}
	else if (d->l.line[d->l.i] && d->l.line[d->l.i] == '"'
		&& d->l.line[d->l.i + 1])
		parsing_dol_5(d, l);
	else
		parsing_dol_4(d, l);
}

void	parsing_dol_3(t_struct *d)
{
	d->l.teub = ft_itoa(d, g_global.g_build_error_exec);
	d->l.sub = ft_itoa(d, g_global.g_build_error_exec);
	d->l.tmp2 = ft_strjoin(d->l.tmp, d->l.sub);
	free_str(d->l.sub);
	free_str(d->l.tmp);
	d->l.tmp = d->l.tmp2;
	free_str(d->l.teub);
	d->l.i++;
}

void	parsing_dol_6(t_struct *d, t_list *l, int count)
{
	d->l.i++;
	while (d->l.line[d->l.i] && d->l.line[d->l.i] != '$'
		&& d->l.line[d->l.i] != ' ')
	{
		count++;
		d->l.i++;
	}
	d->l.sub = ft_substr(d->l.line, d->l.i - count, count);
	d->l.env = search_env(l, d->l.sub);
	if (d->l.env != NULL)
	{
		d->l.tmp2 = ft_strjoin(d->l.tmp, d->l.env);
		free_str(d->l.tmp);
		d->l.tmp = d->l.tmp2;
	}
	free_str(d->l.env);
	free_str(d->l.sub);
	d->l.i--;
}

void	parsing_dol_4(t_struct *d, t_list *l)
{
	int	count;

	count = 0;
	if (d->l.line[d->l.i] == '<' || d->l.line[d->l.i] == '>')
		d->l.chev_echo = 0;
	if (d->l.line[d->l.i] == '$' && d->l.line[d->l.i + 1]
		&& d->l.line[d->l.i + 1] == '?')
		parsing_dol_3(d);
	else if (d->l.line[d->l.i] == '$' && d->l.line[d->l.i + 1])
		parsing_dol_6(d, l, count);
	else if (d->l.line[d->l.i] && d->l.line[d->l.i] == ' ')
	{
		d->l.tmp = cat_char_malloc(d->l.tmp, d->l.line[d->l.i++]);
		while (d->l.line[d->l.i] && d->l.line[d->l.i] == ' ')
			d->l.i++;
		d->l.i--;
	}
	else
		d->l.tmp = cat_char_malloc(d->l.tmp, d->l.line[d->l.i]);
}

void	parsing_dol_5(t_struct *d, t_list *l)
{
	d->l.i++;
	while (d->l.line[d->l.i] && d->l.line[d->l.i] != '"')
	{
		d->l.c = 0;
		if (d->l.line[d->l.i] == '<' || d->l.line[d->l.i] == '>')
			d->l.chev_echo = 1;
		if (d->l.line[d->l.i] == '$' && d->l.line[d->l.i + 1]
			&& d->l.line[d->l.i + 1] == '?')
		{
			parsing_dol_3(d);
			d->l.i++;
		}
		else if (d->l.line[d->l.i] == '$')
			parsing_dol_7(d, l);
		else
			d->l.tmp = cat_char_malloc(d->l.tmp, d->l.line[d->l.i++]);
	}
}
