#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr++ = (unsigned char)c;
		i++;
	}
	return (s);
}
