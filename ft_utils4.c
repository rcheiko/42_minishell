#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (word);
}

char	*tab_malloc(const char *str, char c)
{
	int		i;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	tab = (char *)malloc(sizeof(char) * i + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		i_tab;
	int		total_word;
	char	**tab;

	i = 0;
	i_tab = 0;
	total_word = count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * total_word + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[i_tab] = tab_malloc(s + i, c);
			i_tab++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[i_tab] = 0;
	return (tab);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
