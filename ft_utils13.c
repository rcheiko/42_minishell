#include "minishell.h"

void	modify_old_pwd(t_struct *d, t_list *l)
{
	int		len;
	char	*tmp;
	char	*pwd;
	char	*res;
	t_elem	*count;

	len = -1;
	count = l->first;
	pwd = NULL;
	res = NULL;
	d->l.i = get_oldpwd_pos(l);
	d->l.j = get_pwd_pos(l);
	while (++len < d->l.j)
		count = count->next;
	len = -1;
	tmp = ft_strchr(count->data, '=');
	count = l->first;
	while (++len < d->l.i)
		count = count->next;
	pwd = ft_substr(count->data, 0, ft_strlen_egal(count->data));
	res = ft_strcat_malloc(pwd, tmp);
	free_str(pwd);
	free_str(count->data);
	count->data = ft_strdup(res);
	free_str(res);
}

void	modify_pwd(t_struct *d, t_list *l)
{
	int		len;
	char	*pp;
	char	*path;
	char	*res;

	d->l.i = -1;
	len = 0;
	pp = malloc(100);
	getcwd(pp, 100);
	path = ft_strdup("PWD=");
	res = malloc(sizeof(char) * 5 + ft_strlen(pp));
	while (path[++d->l.i])
		res[d->l.i] = path[d->l.i];
	while (pp[len])
		res[d->l.i++] = pp[len++];
	res[d->l.i] = '\0';
	modify_pwd_2(d, l, pp, res);
	free_str(path);
}

void	modify_pwd_2(t_struct *d, t_list *l, char *pp, char *res)
{
	int		len;
	t_elem	*count;

	len = -1;
	count = l->first;
	d->l.i = get_pwd_pos(l);
	while (++len < d->l.i)
		count = count->next;
	free_str(count->data);
	count->data = res;
	free_str(pp);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char			*strf;
	int				i;
	unsigned int	lens;

	lens = ft_strlen(s);
	i = 0;
	if (start > lens)
	{
		strf = malloc(sizeof(char) * 1);
		if (strf == NULL)
			return (NULL);
		return (strf);
	}
	strf = malloc(sizeof(char) * len + 1);
	if (strf == NULL)
		return (NULL);
	while (s[start] && len != 0)
	{
		if (len == 0)
			return (strf);
		strf[i++] = s[start++];
		len--;
	}
	strf[i] = '\0';
	return (strf);
}

void	afflst_n(t_list *lst)
{
	t_elem	*courant;

	courant = lst->first;
	printf("%s\n", courant->data);
	while (courant->next != NULL)
	{
		courant = courant->next;
		printf("%s\n", courant->data);
	}
	printf("NULL");
}
