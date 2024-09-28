#include "libft.h"

char	*ft_freejoin(char *s1, char *s2, int sizeS1, int sizeS2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	dest = malloc((sizeS1 + sizeS2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < sizeS1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < sizeS2)
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = '\0';
	return (dest);
}
