
#include "../libft/libft.h"
#include "../minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>


int	change_input(t_shell *input, char *veriable, int plen, int i)
{
	char *newinput;
	int len;
	int vlen;
	int j;
	int k;

	j = -1;
	k = i;
	vlen = 0;
	if (veriable != NULL)
		vlen = ft_strlen(veriable);
	len = ft_strlen(input->input);
	newinput = malloc((len - plen) + vlen + 1);
	if (!newinput)
		return (i);
	ft_strlcpy(newinput, input->input, i + 1);
	while (veriable && veriable[++j])
		newinput[i++] = veriable[j];
	ft_strlcpy(newinput + i, input->input + (k + plen + 1), len - (k + plen + 1)
		+ 1);
	free(input->input);
	input->input = newinput;
	return (i - 1);
}

int	find_path(t_shell *input, int i, int point)
{
	char *path;
	char *veriable;
	int j;

	j = i;
	if (input->input[i + 1] == '?')
	{
		veriable = ft_itoa(input->exit_code);
		i = change_input(input, veriable, 1, i);
		free(veriable);
		return (i + 1);
	}
	// while ((ft_isalnum(input->input[j + 1]) || input->input[j + 1] == '_'))
	// {
	// 	if (point == 1)
	// 	{
	// 		j++;
	// 		break ;
	// 	}
	// 	j++;
	// }
	while (point != 1 && (ft_isalnum(input->input[j + 1]) || input->input[j+ 1] == '_'))
		j++;
	if (point == 1)
		j++;
	path = ft_substr(input->input, i + 1, j - i);
	veriable = ft_getenv(input->env, path);
	i = change_input(input, veriable, ft_strlen(path), i);
	free(path);
	return (i);
}

int	dollar_handle(t_shell *ipt, char point, int i)
{
	int flag;

	flag = 0;
	while (ipt->input[i] && ipt->input[i++] != '"' && flag == 0)
	{
		if (point == '$')
			flag = 1;
		if (ipt->input[i - 1] == '$')
		{
			if (ft_isdigit(ipt->input[i]))
				i = find_path(ipt, i - 1, 1);
			else if (ft_isalpha(ipt->input[i]) || ipt->input[i] == '_')
				i = find_path(ipt, i - 1, 0);
			else if (ipt->input[i] == '?')
				i = find_path(ipt, i - 1, 0);
			else if (flag == 1 && (ipt->input[i] == 34 || ipt->input[i] == 39))
				i = find_path(ipt, i - 1, 0);
		}
	}
	if (point == '$')
		return (i - 1);
	return (i);
}

int	heredock_dollar(t_shell *input, int i)
{
	i += 2;
	while (input->input[i] == ' ')
		i++;
	while (input->input[i] != ' ' && input->input[i] != '|'
		&& input->input[i] != '\0')
	{
		if (input->input[i] == 34 || input->input[i] == 39)
		{
			input->qut = input->input[i];
			i++;
			while (input->input[i] != input->qut && input->input[i] != '\0')
				i++;
		}
		i++;
	}
	i++;
	return (i);
}

void	dollar_expand(t_shell *input)
{
	int i;

	i = 0;
	while (input->input[i])
	{
		if (input->input[i] == '"')
			i = dollar_handle(input, input->input[i], i + 1);
		if (input->input[i] == '\'')
			i = quotes_skip(input->input, i, 1, 0);
		if (input->input[i] == '<' && input->input[i + 1] == '<')
			i = heredock_dollar(input, i);
		if (input->input[i] == '$')
			i = dollar_handle(input, input->input[i], i);
		i++;
	}
}
