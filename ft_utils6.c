#include "minishell.h"

void	ft_strcpy_wspa(char *src, char *dest)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (src[i] == ' ' && src[i])
		i++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

void	del_space_start(t_struct *d)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof (char) * (ft_len_wspa(d->l.line) + 1));
	ft_strcpy_wspa(d->l.line, str);
	free(d->l.line);
	d->l.line = NULL;
	d->l.line = malloc(sizeof (char) * ft_strlen(str) + 1);
	ft_strcpy(d->l.line, str);
	free(str);
	str = NULL;
}

int	ft_len_wspa_end(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' && str[i])
		i--;
	while (str[i])
	{
		i--;
		j++;
	}
	return (j);
}

void	ft_strcpy_wspa_end(char *src, char *dest)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(src) - 1;
	while (src[i] == ' ' && src[i])
		i--;
	dest[i + 1] = '\0';
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
}

void	del_space_end(t_struct *d)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof (char) * (ft_len_wspa_end(d->l.line) + 1));
	ft_strcpy_wspa_end(d->l.line, str);
	free(d->l.line);
	d->l.line = NULL;
	d->l.line = malloc(sizeof (char) * ft_strlen(str) + 1);
	ft_strcpy(d->l.line, str);
	free(str);
	str = NULL;
}
