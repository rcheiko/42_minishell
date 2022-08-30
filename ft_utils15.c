#include "minishell.h"

char	*search_env(t_list *l, char *str)
{
	t_elem	*c;
	int		tmp;
	int		mal;
	char	*res;

	c = l->first;
	tmp = ft_strlen(str) + 1;
	mal = 0;
	while (c->next != NULL)
	{
		if (ft_strncmp(str, c->data, ft_strlen(str)) == 0
			&& ft_strncmp(str, c->data, ft_strlen_egal(c->data)) == 0)
		{
			while (c->data[tmp])
			{
				mal++;
				tmp++;
			}
			res = search_env_2(c, str, tmp, mal);
			return (res);
		}
		c = c->next;
	}
	return (NULL);
}

char	*search_env_2(t_elem *courant, char *str, int tmp, int mal)
{
	char	*res;

	res = malloc(sizeof (char) * (mal + 1));
	if (res == NULL)
		return (NULL);
	tmp = ft_strlen(str) + 1;
	mal = 0;
	while (courant->data[tmp])
		res[mal++] = courant->data[tmp++];
	res[mal] = '\0';
	return (res);
}

int	ft_putchar_int(int c)
{
	unsigned char	s;

	s = (unsigned char) c;
	write(1, &c, 1);
	return (s);
}

void	check_q3(t_struct *d, int i, char *str)
{
	str = check_q2(d, i, str);
	if (d->l.line)
		free_str(str);
}
