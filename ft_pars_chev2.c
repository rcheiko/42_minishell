#include "minishell.h"

int	fill_chevron_2(t_struct *d, int i, int j, char *tmp)
{
	if ((d->l.line[i + 1] && d->l.line[i] == '>' && d->l.line[i + 1] != '>')
		|| (d->l.line[i + 1] && d->l.line[i] == '<' && d->l.line[i + 1] != '<'))
	{
		d->l.chevrons[j] = d->l.line[i];
		d->l.chevrons[j + 1] = '\0';
		tmp = ft_strdup(d->l.chevrons);
		free_str(d->l.chevrons);
		d->l.chevrons = ft_strjoin(tmp, "$");
		free_str(tmp);
		j += 2;
	}
	return (j);
}

void	che_to_tab(t_struct *d)
{
	d->l.chetab = ft_split1(d->l.line, "><");
	d->l.chetab_cd = ft_split1(d->l.line2, "><");
}

void	chev_count(t_struct *d)
{
	int	i;

	i = 0;
	while (d->l.chev_tab && d->l.chev_tab[i] != NULL)
		i++;
	d->l.ch_nb = i;
}
