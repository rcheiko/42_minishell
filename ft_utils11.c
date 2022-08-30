#include "minishell.h"

int	ft_lstsize(t_list *l)
{
	t_elem	*count;
	int		i;

	count = l->first;
	i = 0;
	while (count != NULL)
	{
		count = count->next;
		i++;
	}
	return (i);
}

int	ft_strlen_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	get_pwd_pos(t_list *l)
{
	int		i;
	t_elem	*count;

	count = l->first;
	i = 0;
	while (count != NULL)
	{
		if (ft_strncmp(count->data, "PWD", 3) == 0)
			return (i);
		count = count->next;
		i++;
	}
	return (0);
}

int	get_oldpwd_pos(t_list *l)
{
	int		i;
	t_elem	*count;

	i = 0;
	count = l->first;
	while (count != NULL)
	{
		if (ft_strncmp(count->data, "OLDPWD", 6) == 0)
			return (i);
		i++;
		count = count->next;
	}
	return (0);
}

void	init(t_list *l)
{
	l->first = NULL;
	l->last = NULL;
}
