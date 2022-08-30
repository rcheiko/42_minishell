#include "minishell.h"

int	len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(t_struct *d, int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	str = malloc(sizeof(char) * (d->l.len + 1));
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

void	exec_chev_last_out_bin(t_struct *d, int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(d->l.fd3, STDIN_FILENO);
	close(d->l.fd3);
}

void	exec_chev_last_in_bin(int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
}

char	**ft_cmd_chev_left(t_struct *d, int i)
{
	int		j;
	char	*line;
	char	**cmd;
	char	*tmp;

	j = 0;
	while (d->l.line[j] && d->l.line[j] != '>' && d->l.line[j] != '<')
		j++;
	line = ft_substr(d->l.line, 0, j - 1);
	tmp = ft_strjoin(line, " ");
	line = ft_strjoin(tmp, d->l.chetab[i]);
	cmd = ft_split(line, ' ');
	return (cmd);
}
