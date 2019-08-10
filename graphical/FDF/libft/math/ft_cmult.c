#include "libft.h"

inline t_coord	ft_cmult(t_coord z1, t_coord z2)
{
	return (ft_coord(
				z1.x * z2.x - z1.y * z2.y,
				z1.x * z2.y + z1.y * z2.x	
				));
}
