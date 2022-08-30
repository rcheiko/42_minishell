#include "minishell.h"

char	*cat_export(char *dest, char *src)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_strlen(dest) + ft_strlen(src));
	while (dest[i] != '\0')
	{
		res[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		res[i] = src[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

void	env_export(char **envp, t_list *l)
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

char	*str_cat_remake(char *dest)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	len = ft_strlen_egal(dest) + 1;
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_strlen(dest) + 3);
	while (i < len)
		res[i++] = dest[j++];
	res[i] = '"';
	i++;
	while (dest[j])
		res[i++] = dest[j++];
	res[i] = '"';
	res[++i] = '\0';
	return (res);
}

void	export_env_declare(t_list *l)
{
	t_elem	*count;
	char	*res;
	char	*tmp;

	count = l->first;
	res = NULL;
	while (count != NULL)
	{
		tmp = str_cat_remake(count->data);
		free_str(count->data);
		res = cat_export("declare -x ", tmp);
		free_str(tmp);
		count->data = ft_strdup(res);
		free_str(res);
		count = count->next;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = NULL;
	c = *a;
	*a = *b;
	*b = c;
}
