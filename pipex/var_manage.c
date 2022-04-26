#include "pipex.h"

char	*analyze_command(char **paths, char *command)
{
	char	*tmp;
	char	*path_to_command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path_to_command = ft_strjoin(tmp, command);
		free(tmp);
		if (access(path_to_command, F_OK) == 0)
			return (path_to_command);
		free(path_to_command);
		paths++;
	}
	return (NULL);
}

char *find_path(char **envp)
{
    int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
