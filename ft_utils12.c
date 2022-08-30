#include "minishell.h"

char	*ft_strchr(char *s, int c)
{
	char	car;
	char	*dst;
	int		i;

	i = 0;
	car = c;
	dst = (char *)s;
	while (dst[i])
	{
		if (dst[i] == car)
			return (&dst[i]);
		i++;
	}
	if (car == '\0')
		return (&dst[i]);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*begin;
	char	*start;
	char	*end;
	int		size;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (is_set(s1[i], set) == 1)
		i++;
	start = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	while (is_set(s1[i], set) == 1)
		i--;
	end = (char *)&s1[i];
	if (!*s1 || ft_strlen(start) == ft_strlen(end))
		size = 2;
	else
		size = end - start + 2;
	begin = (char *)malloc(sizeof(char) * size);
	if (begin == NULL)
		return (NULL);
	ft_strlcpy(begin, start, size);
	return (begin);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int		len;
	int		i;
	char	*sr;

	i = 0;
	sr = (char *)src;
	if (!sr)
		return (0);
	len = ft_strlen(src);
	if (dst == '\0')
		return (0);
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	pushfront_one(t_list *l, char *val)
{
	t_elem	*nouv;
	t_elem	*count;

	nouv = malloc(sizeof(t_elem));
	count = l->first->next;
	if (!nouv)
		exit(0);
	nouv->data = val;
	count->prec = nouv;
	nouv->next = count;
	l->first->next = nouv;
	nouv->prec = l->first;
}
