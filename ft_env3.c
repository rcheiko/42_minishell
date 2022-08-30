#include "minishell.h"

int	ft_strcmp_alph(char *s1, char *s2)
{
	int	i;

	i = 11;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}

void	alphabetic_order(t_list *l)
{
	t_elem	*count;
	int		len;
	int		i;

	count = l->first;
	i = 0;
	len = ft_lstsize(l);
	while (i < len - 1)
	{
		if (ft_strcmp_alph(count->data, count->next->data) == 1)
		{
			ft_swap(&count->data, &count->next->data);
			i = 0;
			count = l->first;
		}
		else
		{
			count = count->next;
			i++;
		}
	}
}

void	update_my_envp(t_struct *d, t_list *l)
{
	t_elem	*count;
	int		i;
	int		j;

	j = -1;
	count = l->first;
	i = -1;
	if (d->my_envp)
		free_char_tab(d->my_envp);
	i = ft_lstsize(l);
	d->my_envp = malloc(sizeof(char *) * (i + 1));
	while (++j < i)
	{
		d->my_envp[j] = ft_strdup(count->data);
		count = count->next;
	}
	d->my_envp[j] = NULL;
}
