#include "minishell.h"

void	echo_parse(t_struct *d)
{
	d->l.i_e = 5;
	d->l.echo_n = 0;
	if (d->l.line[5] && d->l.line[5] == '-'
		&& d->l.line[6] && d->l.line[6] == 'n')
		echo_parse_n(d);
	while (d->l.line[d->l.i_e])
	{
		printf("%c", d->l.line[d->l.i_e]);
		d->l.i_e++;
	}
	if (d->l.echo_n != 1)
		printf("\n");
}

void	echo_parse_n(t_struct *d)
{
	int	tmp;

	tmp = 0;
	while (d->l.line[d->l.i_e])
	{
		if (d->l.line[d->l.i_e] != '-')
			return ;
		if (d->l.line[d->l.i_e] == '-')
		{
			tmp = d->l.i_e;
			d->l.i_e++;
			while (d->l.line[d->l.i_e] && d->l.line[d->l.i_e] != ' ')
			{
				if (d->l.line[d->l.i_e] != 'n')
				{
					d->l.i_e = tmp;
					return ;
				}
				d->l.i_e++;
			}
		}
		d->l.echo_n = 1;
		d->l.i_e++;
	}
}

void	echo_parse_chev(t_struct *d)
{
	d->l.i_e = 5;
	d->l.echo_n = 0;
	if (d->l.chetab[0][5] && d->l.chetab[0][5] == '-'
		&& d->l.chetab[0][6] && d->l.chetab[0][6] == 'n')
		echo_parse_n_chev(d);
	while (d->l.chetab[0][d->l.i_e])
	{
		printf("%c", d->l.chetab[0][d->l.i_e]);
		d->l.i_e++;
	}
	if (d->l.echo_n != 1)
		printf("\n");
}

void	echo_parse_n_chev(t_struct *d)
{
	int	tmp;

	tmp = 0;
	while (d->l.chetab[0][d->l.i_e])
	{
		if (d->l.chetab[0][d->l.i_e] != '-')
			return ;
		if (d->l.chetab[0][d->l.i_e] == '-')
		{
			tmp = d->l.i_e;
			d->l.i_e++;
			while (d->l.chetab[0][d->l.i_e] && d->l.chetab[0][d->l.i_e] != ' ')
			{
				if (d->l.chetab[0][d->l.i_e] != 'n')
				{
					d->l.i_e = tmp;
					return ;
				}
				d->l.i_e++;
			}
		}
		d->l.echo_n = 1;
		d->l.i_e++;
	}
}
