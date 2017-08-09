#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int		i;
	void	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*((int *)ptr++) = c;
		i++;
	}
	return (s);
}
