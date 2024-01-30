#include <stdlib.h>
#include <fcntl.h>
#include "../so_long.h"

int	map_tester(char	*map_path)
{
	int	fd;
	fd = open(map_path, O_RDONLY);
	wall_checker(fd);
}

int	wall_checker(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
	}

}
