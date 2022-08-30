#include "minishell.h"

int	search_space(t_struct *d)
{
	int	i;

	i = 2;
	while (d->l.line2[i])
	{
		if (d->l.line2[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	search_space_cd(t_struct *d)
{
	int	i;

	i = 2;
	while (d->l.chetab_cd[0][i])
	{
		if (d->l.chetab_cd[0][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcat_malloc(char *dest, char *src)
{
	int		i;
	int		j;
	int		len;
	int		len2;
	char	*res;

	len = ft_strlen(dest);
	len2 = ft_strlen(src);
	res = malloc(len + len2 + 1);
	i = 0;
	j = 0;
	while (dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		res[i] = src[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

void	del_space_end_che(t_struct *d)
{
	int		i;
	char	*str;

	i = 0;
	while (d->l.chetab[i])
	{
		str = malloc(sizeof (char) * (ft_len_wspa_end(d->l.chetab[i]) + 1));
		ft_strcpy_wspa_end(d->l.chetab[i], str);
		free(d->l.chetab[i]);
		d->l.chetab[i] = malloc(sizeof (char) * ft_strlen(str) + 1);
		ft_strcpy(d->l.chetab[i], str);
		free(str);
		str = NULL;
		i++;
	}
}
