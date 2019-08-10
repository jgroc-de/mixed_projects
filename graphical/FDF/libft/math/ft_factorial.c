#include "libft.h"

int	ft_factorial(int k)
{
	int	out;

	out = 1;
	while (k > 1)
	{
		out *= k--;
	}
	return (out);
}
