#include "minishell.h"

int	is_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	is_char_c(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

void	mal_cpy_echo(t_struct *d)
{
	int	j;
	int	tmp;
	int	mal;

	j = find_str_echo(d);
	tmp = j;
	mal = 0;
	while (d->l.line[j])
	{
		j++;
		mal++;
	}
	j = 0;
	d->l.echo = malloc(sizeof (char) * (mal + 1));
	while (d->l.line[tmp])
	{
		d->l.echo[j] = d->l.line[tmp];
		tmp++;
		j++;
	}
	d->l.echo[j] = '\0';
}

int	find_str_echo(t_struct *d)
{
	int	j;
	int	tiret;
	int	count;

	j = 0;
	count = 0;
	tiret = count_arg(d->l.line);
	while (d->l.line[j] && d->l.line[j] != ' ')
		j++;
	j++;
	j = find_str_echo_1(d, j, tiret);
	return (j);
}
