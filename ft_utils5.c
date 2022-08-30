#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s && fd)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

int	ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	ft_isdigit(int c)
{
	if (c == 0)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_len_wspa(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}
