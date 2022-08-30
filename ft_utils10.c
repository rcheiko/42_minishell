#include "minishell.h"

char	*del_plus_egal(char *str)
{
	char	*res;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	res = malloc(ft_strlen(str));
	while (str[k] && str[k] != '+')
		k++;
	while (str[i])
	{
		if (i != k)
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	del_cell(t_list *l, int index)
{
	int		i;
	t_elem	*courant;

	courant = l->first;
	i = 0;
	while (i < index)
	{
		courant = courant->next;
		i++;
	}
	if (courant->next == NULL)
		courant->prec->next = NULL;
	else if (courant->prec == NULL)
		courant->next->prec = NULL;
	else
	{
		courant->next->prec = courant->prec;
		courant->prec->next = courant->next;
	}
	free_str(courant->data);
	free(courant);
}

void	del_cell_nofree(t_list *l, int index)
{
	int		i;
	t_elem	*courant;

	courant = l->first;
	i = 0;
	while (i < index)
	{
		courant = courant->next;
		i++;
	}
	if (courant->next == NULL)
		courant->prec->next = NULL;
	else if (courant->prec == NULL)
		courant->next->prec = NULL;
	else
	{
		courant->next->prec = courant->prec;
		courant->prec->next = courant->next;
	}
	free(courant);
}

int	ft_strlen_twochar(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_struct(t_struct *d)
{
	d->env = NULL;
	d->my_envp = NULL;
	d->str = NULL;
	d->cd = NULL;
	d->line = NULL;
	d->l.arg_chev = NULL;
	d->l.tmp = NULL;
	d->l.chevrons = NULL;
	d->l.line = NULL;
	d->l.line2 = NULL;
	d->l.cmd = NULL;
	d->l.echo = NULL;
	d->l.str1 = NULL;
	g_global.g_build_error_exec = 0;
	d->l.pos = 0;
	d->l.fd = 0;
	d->l.fd2 = 0;
}
