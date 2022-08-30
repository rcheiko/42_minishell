#include "minishell.h"

void	del_space_start_che(t_struct *d)
{
	int		i;
	char	*str;

	i = 0;
	while (d->l.chetab[i])
	{
		str = malloc(sizeof (char) * (ft_len_wspa(d->l.chetab[i]) + 1));
		ft_strcpy_wspa(d->l.chetab[i], str);
		free(d->l.chetab[i]);
		d->l.chetab[i] = malloc(sizeof (char) * ft_strlen(str) + 1);
		ft_strcpy(d->l.chetab[i], str);
		free(str);
		str = NULL;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[k++] = s2[j++];
	dest[k] = '\0';
	return (dest);
}

char	*get_binaire(t_struct *d)
{
	char	*str;
	char	*res;

	d->l.i = -1;
	str = ft_strdup(getenv("PATH"));
	d->path = ft_split(str, ':');
	free_str(str);
	while (d->path[++d->l.i])
	{
		d->l.bin = get_binaire_2(d, d->l.i);
		d->l.fd = open(d->l.bin, 0);
		if (d->l.fd > 0)
		{
			d->l.tmp = ft_strdup(d->path[d->l.i]);
			res = ft_strjoin(d->l.tmp, "/");
			free_str(d->l.tmp);
			free_str(d->l.bin);
			free_char_tab(d->path);
			return (res);
		}
		free_str(d->l.bin);
	}
	res = get_binaire_3();
	free_char_tab(d->path);
	return (res);
}

char	*get_binaire_2(t_struct *d, int i)
{
	char	*bin;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(d->path[i]);
	bin = ft_strjoin(tmp, "/");
	free_str(tmp);
	tmp2 = ft_strdup(bin);
	free_str(bin);
	bin = ft_strjoin(tmp2, d->l.cmd);
	free_str(tmp2);
	return (bin);
}

char	*get_binaire_3(void)
{
	char	*res;

	res = NULL;
	res = malloc(1);
	res[0] = '\0';
	return (res);
}
