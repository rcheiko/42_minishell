#include "minishell.h"

int	is_chevron(t_struct *d)
{
	int	i;

	i = 0;
	if (d->l.chev_echo == 0)
	{
		while (d->l.line[i] != '\0' && ft_strlen(d->l.line) > 1)
		{
			i = is_chevron2(d, i);
			if (d->l.line[i] && d->l.line[i] == '\'')
			{
				i++;
				while (d->l.line[i] != '\0' && d->l.line[i] != '\'')
					i++;
			}
			if (d->l.line[i] == '>' || d->l.line[i] == '<')
			{
				if (d->l.line[i] == '<' || d->l.line[i + 1] == '<')
					g_global.g_status = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	is_chevron2(t_struct *d, int i)
{
	if (d->l.line[i] && d->l.line[i] == '"')
	{
		i++;
		while (d->l.line[i] && d->l.line[i] != '"')
		{
			i++;
		}
	}
	return (i);
}

void	fill_chevron(t_struct *d)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	d->l.chevrons = NULL;
	tmp = NULL;
	d->l.chevrons = malloc(sizeof(char) * 2);
	while (d->l.line[i] != '\0')
	{
		j = fill_chevron_2(d, i, j, tmp);
		if ((d->l.line[i + 1] && d->l.line[i] == '<' && d->l.line[i + 1] == '<')
			|| (d->l.line[i + 1]
				&& d->l.line[i] == '>' && d->l.line[i + 1] == '>'))
		{
			fill_chevron_3(d, i, j, tmp);
			j += 3;
			i++;
		}
		i++;
	}
	d->l.chev_tab = NULL;
	d->l.chev_tab = ft_split(d->l.chevrons, '$');
	free_str(d->l.chevrons);
}

void	fill_chevron_3(t_struct *d, int i, int j, char *tmp)
{
	d->l.chevrons[j] = d->l.line[i];
	d->l.chevrons[j + 1] = d->l.line[i + 1];
	d->l.chevrons[j + 2] = '\0';
	tmp = ft_strdup(d->l.chevrons);
	free_str(d->l.chevrons);
	d->l.chevrons = ft_strjoin(tmp, "$");
	free_str(tmp);
}
