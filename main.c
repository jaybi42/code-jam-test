#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

static int	solve_this(int fd)
{
	char	*line;
	char	*r_line;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (get_next_line(fd, &line) < 0)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		printf("case #%i", i);
		j = ft_strlen(line) - 1;
		k = 0;
		while (j >= 0)
		{
			if (line[j] == ' ')
			{
				printf("%.ks", line[j + 1]);
				if (j == 0)
					ft_putchar('\n');
				else
					ft_putchar(' ');
				k = 0;
			}
			k++;
			j--;
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	buf[2048];
	int		ret;
	int		fd;
	int		N;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (1);
	if (solve_this(fd) == 1)
		return (1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}