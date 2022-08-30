#include "minishell.h"

int	get_pos_env(t_list *l, char *env)
{
	t_elem	*count;
	int		i;

	count = l->first;
	i = 0;
	while (count != NULL)
	{
		if (ft_strncmp(count->data, env, ft_strlen_egal(count->data)) == 0
			&& ft_strncmp(count->data, env, ft_strlen_egal(env)) == 0)
			return (i);
		count = count->next;
		i++;
	}
	return (-1);
}

int	get_pos_env_exp(t_list *exp, char *str)
{
	t_elem	*count;
	int		i;
	char	*tmp;

	count = exp->first;
	i = 0;
	tmp = ft_strjoin("declare -x ", str);
	while (count != NULL)
	{
		if (ft_strncmp(count->data, tmp, ft_strlen_egal(tmp)) == 0
			&& ft_strncmp(count->data, tmp, ft_strlen_egal(count->data)) == 0)
		{
			free_str(tmp);
			return (i);
		}
		count = count->next;
		i++;
	}
	free_str(tmp);
	return (-1);
}

void	fill_env(t_struct *d, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	d->env = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (envp[i] != NULL)
	{
		d->env[i] = ft_strdup(envp[i]);
		i++;
	}
	d->env[i] = NULL;
}

void	fill_env_struct(char **envp, t_list *l)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	i = 0;
	while (envp[i] != NULL)
	{
		pushfront(l, ft_strdup(envp[i]));
		i++;
	}
}

int	is_in_env(t_list *l, char *str)
{
	int		i;
	int		j;
	t_elem	*count;

	count = l->first;
	i = ft_strlen_egal(str);
	while (count != NULL)
	{
		if (ft_strncmp(str, count->data, ft_strlen_egal(str)) == 0)
		{
			j = ft_strlen_egal(count->data);
			if (i == j)
				return (1);
		}
		count = count->next;
	}
	return (0);
}
