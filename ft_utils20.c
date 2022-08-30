#include "minishell.h"

char	*cpy_until_space(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	cpy_cmd(t_struct *d)
{
	d->l.cmd = cpy_until_space(d->l.line);
}

int	count_arg(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	return (j);
}

int	ft_strlen_int(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
