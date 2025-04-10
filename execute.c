#include "libft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char *pathc(char *cmd) 
{
    int i;
    char *tmp = getenv("PATH");
    if (!tmp)
        return NULL;

    char **path = ft_split(tmp, ':');
    if (!path)
        return NULL;

    char *arg, *str;
    i = 0;
    while (path[i]) 
    {
        arg = ft_strjoin(path[i], "/");
        str = ft_strjoin(arg, cmd);
        free(arg);
        if (access(str, X_OK) == 0) 
        {
            ft_free(path);
            return str;
        }
        free(str);
        i++;
    }
    ft_free(path);
    return NULL;
}

void ft_execve(char **args) 
{
    if (!args || !args[0])
        exit(1);

    char *base = pathc(args[0]);
    if (!base) 
    {
        perror("Command not found");
        exit(1);
    }
    execve(base, args, NULL);
    perror("execve patladi");
    exit(1);
}

void execute_pipe(char **args) 
{
    int fd[2];
    int prev_fd = -1;
    pid_t pid;
    int i = 0;
    int start = 0;

    while (args[i]) 
    {
        if (strcmp(args[i], "|") == 0) 
        {
            args[i] = NULL;
            pipe(fd);
            pid = fork();
            if (pid == 0) 
            {
                if (prev_fd != -1) 
                {
                    dup2(prev_fd, 0); 
                    close(prev_fd);
                }
                dup2(fd[1], 1);
                close(fd[0]);
                close(fd[1]);
                ft_execve(&args[start]);
            }
            close(fd[1]);
            prev_fd = fd[0];
            start = i + 1;
        }
        i++;
    }
    pid = fork();
    if (pid == 0) 
    {
        if (prev_fd != -1) 
        {
            dup2(prev_fd, 0);
            close(prev_fd);
        }
        ft_execve(&args[start]);
    }
    close(prev_fd);
    while (wait(NULL) > 0);
}

int main() {
    char *input[] = { "sleep", "3", "|", "ls", "|", "wc", "-l", NULL };
    execute_pipe(input);
    return 0;
}