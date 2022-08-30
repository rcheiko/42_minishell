#include "minishell.h"

void	push_frontlst(t_list *lst, char *str)
{
	t_elem	*new;

	new = malloc(sizeof (t_elem));
	if (!new)
		exit(0);
	new->data = ft_strdup(str);
	new->next = lst->first;
	new->prec = NULL;
	if (lst->first)
		lst->first->prec = new;
	else
	{
		lst->last = new;
		lst->last->next = NULL;
	}
	lst->first = new;
}

void	afflst(t_list *lst)
{
	t_elem	*courant;

	courant = lst->last;
	printf("%s\n", courant->data);
	while (courant->prec != NULL)
	{
		courant = courant->prec;
		printf("%s\n", courant->data);
	}
}

void	afflst_back(t_list *exp)
{
	t_elem	*count;

	count = exp->first;
	while (count != NULL)
	{
		if (count->data != NULL)
			printf("%s\n", count->data);
		count = count->next;
	}
}

void	check_q(t_struct *d)
{
	char	*str;
	int		i;

	if (d->l.line)
		str = malloc(ft_strlen(d->l.line));
	i = 0;
	if (d->l.line && d->l.line[0] == '\'')
	{
		i++;
		while (d->l.line[i])
		{
			if (d->l.line[i] != '\'' && d->l.line[i] == ' ')
				str[i - 1] = d->l.line[i];
			else if (d->l.line[i] == '\'' && d->l.line[i + 1] == '\0')
			{
				str[i - 1] = '\0';
				printf("bash: %s: command not found\n", str);
			}
			else
				break ;
			i++;
		}
	}
	check_q3(d, i, str);
}

char	*check_q2(t_struct *d, int i, char *str)
{
	if (d->l.line && d->l.line[0] == '"')
	{
		i++;
		while (d->l.line[i])
		{
			if (d->l.line[i] != '"' && d->l.line[i] == ' ')
				str[i - 1] = d->l.line[i];
			else if (d->l.line[i] == '"' && d->l.line[i + 1] == '\0')
			{
				str[i - 1] = '\0';
				printf("bash: %s: command not found\n", str);
			}
			else
				break ;
			i++;
		}
	}
	return (str);
}
