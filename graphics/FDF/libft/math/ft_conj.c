#include "libft.h"

inline t_coord	ft_conj(t_coord z)
{
	z.y = -z.y;
	return (z);
}
