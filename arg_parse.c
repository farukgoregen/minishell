#include "libft/libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int	quadot_skip(char *str, int j) // bunuda farklı bir yerde tanımla
{
	int i;
	char qut;

	i = j;
	if (str[i] == 34 || str[i] == 39)
	{
		qut = str[i++];
		while (str[i] && str[i] != qut)
			i++;
		if (str[i])
			i++;
	}
	return (i);
}

int	pipe_count(char *str) // bu fonksiyona gerek yok emptylineda yap
{
	int i;
	int count;

	i = -1;
	count = 0;

	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = quadot_skip(str, i);

		if (str[i] == '|')
			count++;
	}
	if (count==0)
		count=1;
	return (count);
}

=======
>>>>>>> main
char	*strcut(char *str, int start, int end, int size)
{
	int		i;
	int		j;
	char	*newstr;

<<<<<<< HEAD

	if (size<=0)
		return NULL;
	newstr = malloc(size + 1);
=======
	if (size <= 0)
		return (NULL);
	newstr = malloc(size + 1);
	if (!newstr)
		return (NULL);
>>>>>>> main
	i = -1;
	j = 0;
	while (str[++i])
	{
<<<<<<< HEAD
		if (i == start)
		{
			while (i <= end)
				i++;
		}
=======
		if (i >= start && i <= end)
			continue ;
>>>>>>> main
		newstr[j] = str[i];
		j++;
	}
	newstr[j] = '\0';
<<<<<<< HEAD
=======
	free(str);
>>>>>>> main
	return (newstr);
}

char	*redirect_skip(char **redirect, char *str, int *t)
{
	int	j;
	int	k;
<<<<<<< HEAD
	int i;

	i=*t;
	j = i;
	i++;
	if (str[i] == '<' || str[i] == '>')
	i++;
	
	while (str[i] == ' ')
		i++;
	k = i;
	while (str[i] != ' ' && str[i] != '\0' )
	{
		if (str[i] == 34 || str[i] == 39)
			i = quadot_skip(str, i);
		i++;
	}
	
	*redirect = ft_substr(str, k, i - k);
	
	str = strcut(str, j, i, ft_strlen(str) - (i - j));
	*t=-1;
=======
	int	i;

	i = *t;
	j = i;
	i++;
	if (str[i] == '<' || str[i] == '>')
		i++;
	while (str[i] == ' ')
		i++;
	k = i;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
			i = quotes_skip(str, i);
		i++;
	}
	*redirect = ft_substr(str, k, i - k);
	str = strcut(str, j, i, ft_strlen(str) - (i - j));
	*t = -1;
>>>>>>> main
	return (str);
}

char	*redirect_convert(t_input *ipt, char *str, int k)
{
	int	i;
<<<<<<< HEAD
	i = -1;
	while (str[++i])
	{
		if (str[i]== 34 || str[i]== 39)
		i = quadot_skip(ipt->input, i);
		if (str[i]== '<' && ipt->input[i + 1] == '<'){
			str = redirect_skip(&ipt->arg[k]->heradock, str, &i);
		}
		else if (str[i]== '<')
			str = redirect_skip(&ipt->arg[k]->infile, str, &i);
		else if (str[i]== '>' && ipt->input[i + 1] == '>')
			str = redirect_skip(&ipt->arg[k]->append_outfile, str, &i);
		else if (str[i]== '>')
			str = redirect_skip(&ipt->arg[k]->outfile, str, &i);
		if (!str)
			return NULL;
	}
	return str;
}
=======

	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = quotes_skip(str, i);
		if (str[i] == '<' && str[i + 1] == '<')
			str = redirect_skip(&ipt->arg[k]->heradock, str, &i);
		else if (str[i] == '<')
			str = redirect_skip(&ipt->arg[k]->infile, str, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			str = redirect_skip(&ipt->arg[k]->append_outfile, str, &i);
		else if (str[i] == '>')
			str = redirect_skip(&ipt->arg[k]->outfile, str, &i);
		if (!str)
			return (NULL);
	}
	return (str);
}



>>>>>>> main
void	arg_parse(t_input *ipt, int len, int k)
{
	int		i;
	int		j;
	char	*fakestr;

<<<<<<< HEAD
	if (ipt->error > 0)
		return ;
	i = -1;
	j = 0;
	ipt->arg = malloc(sizeof(t_pro *) * pipe_count(ipt->input));
	while (ipt->input[++i] && i < len)
	// len'i koymayınca fazladan 1 kere daha giriyor
	{
		if (ipt->input[i] == 34 || ipt->input[i] == 39)
			i = quadot_skip(ipt->input, i);
=======
	if (ipt->error > 0 || !ipt->input)
		return ;
	i = -1;
	j = 0;
	ipt->arg = malloc(sizeof(t_pro *) * (ipt->pipe + 1));
	if (!ipt->arg)
		return ;
	while (ipt->input[++i] && i < len)
	// len'i koymayınca fazladan 1 kere daha giriyor
	{
>>>>>>> main
		if (ipt->input[i] == '|' || (ipt->input[i + 1] == '\0'))
		{
			if (ipt->input[i + 1] == '\0')
				i++;
			fakestr = ft_substr(ipt->input, j, i - j);
			ipt->arg[k] = malloc(sizeof(t_pro));
<<<<<<< HEAD
			fakestr = redirect_convert(ipt, fakestr, k);
				
			k++;
			if (fakestr)
				printf("%s\n", fakestr);
=======
			if (!ipt->arg[k])
				return ;
			fakestr = redirect_convert(ipt, fakestr, k);
			arg_convert(ipt, fakestr, k);
			k++;
>>>>>>> main
			free(fakestr);
			j = i + 1;
		}
	}
<<<<<<< HEAD
=======
	ipt->arg[k] = NULL;
>>>>>>> main
}
