#include "libft.h"

t_coord	ft_cdiv(t_coord dividende, t_coord diviseur)
{
	t_coord	conjug;

	conjug = ft_conj(diviseur);
	diviseur = ft_cmult(diviseur, conjug);
	if (diviseur.x != 0)
	{
		dividende = ft_cmult(dividende, conjug);
		dividende.x /= diviseur.x;
		dividende.y /= diviseur.x;
	}
	return (dividende);
}
