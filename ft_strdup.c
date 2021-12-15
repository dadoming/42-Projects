#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc((1 + ft_strlen(str)) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
