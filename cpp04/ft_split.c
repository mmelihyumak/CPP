
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	countword(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		flag;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	wordlen(char const *s, char c)
{
	size_t	i;
	size_t	lenw;

	i = 0;
	lenw = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		lenw++;
	}
	return (lenw);
}

static char	*createword(char const *s, char c)
{
	char	*string;
	size_t	i;

	i = 0;
	string = malloc(sizeof(char) * wordlen(s, c) + 1);
	while (*s && *s != c)
	{
		string[i] = *(s++);
		i++;
	}
	string[i] = 0;
	return (string);
}

char	**ft_split(const char *s, char c)
{
	char	**strings;
	size_t	wordnumber;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	wordnumber = countword(s, c);
	strings = malloc(sizeof(char *) * (wordnumber + 1));
	if (!strings)
		return (0);
	i = 0;
	j = 0;
	while (j < wordnumber && s[i])
	{
		while (s[i] == c)
			i++;
		strings[j] = createword(&s[i], c);
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	strings[j] = 0;
	return (strings);
}