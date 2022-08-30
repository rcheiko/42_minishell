#include "minishell.h"

void	pushfront(t_list *l, char *val)
{
	t_elem	*nouv;

	nouv = malloc(sizeof(t_elem));
	if (!nouv)
		exit(0);
	nouv->data = val;
	nouv->next = l->first;
	nouv->prec = NULL;
	if (l->first)
		l->first->prec = nouv;
	else
		l->last = nouv;
	l->first = nouv;
}

void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_char_tab(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

int	exit_arg(t_struct *d)
{
	if (d->l.arg[1] != NULL && ft_strlen_twochar(d->l.arg) == 2
		&& is_char(d->l.arg[1]) == 0 && check_char(d->l.arg[1]) == 0
		&& ft_strlen_minus(d->l.arg[1]) <= 1)
	{
		g_global.g_build_error_exec = ft_atoi(d->l.arg[1]);
		printf("exit\n");
	}
	else if ((d->l.arg[1] && check_char(d->l.arg[1]) == 1)
		|| (is_char(d->l.arg[1])))
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", d->l.arg[1]);
		exit (255);
	}
	else if (ft_strlen_minus(d->l.arg[1]) > 1)
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", d->l.arg[1]);
		exit (255);
	}
	else
	{
		printf("exit\nbash: exit: too many arguments\n");
		g_global.g_build_error_exec = 1;
		return (1);
	}
	return (2);
}

int	ft_strlen_minus(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	return (j);
}
