#include "main.h"

int		main(void)
{
	//	static char	**store;
    // store = ft_strsplit(COL_STR, ',');

	int i;
	// char *cs;
	static char **ca;

	if (!ca)
	{
		ca = ft_strsplit(C0 C1 C2 C3 C4 C5 C6 C7 C8 C9, ',');
	// 	cs = ft_strjoinfree(cs, ft_strjoinfree())
	// 	ca = ft_strsplit(cs, ',');
	}
	i = 0;
	while (ca[i])
	{
		ft_putstr(ca[i]);
		ft_putnbr(i);
		ft_putstr(CLEAR);
		ft_putchar('\n');
		i++;
	}
	return (0);

}