#include "minishell.h"

int	find_str_echo_1(t_struct *d, int j, int tiret)
{
	int	count;
	int	tmp;

	count = 0;
	if (d->l.line[j] != '-')
		return (j);
	while (tiret >= 1 && count != tiret)
	{
		if (d->l.line[j] == '-')
		{
			count++;
			if (d->l.line[j + 1] != 'n')
				return (j);
			else
			{
				tmp = j++;
				while (d->l.line[j] && d->l.line[j++] != ' ')
					if (d->l.line[j] != ' ' && d->l.line[j] != 'n')
						return (tmp);
			}
		}
		j++;
	}
	return (j - 1);
}
