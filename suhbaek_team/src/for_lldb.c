#include <stdio.h>

void	print(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		printf("%s", str[idx]);
		idx ++;
	}
}
