#include "get_next_line.h"

char *get_next_line(int fd)
{
	int rd;
	int i;
	char *buffer;
	char c;
	buffer = malloc(50000);	i = -1;
	while((rd = read(fd, &c, BUFFER_SIZE * 0 + 1)) > 0) 
	{
		buffer[++i] = c;
		if (buffer[i] == '\n')
			break;
	}
	if ((!buffer[i] && !rd) || rd == -1)
	{
		free(buffer);
		return(NULL);
	}
	i++;
	buffer[i] = '\0';
	return(buffer);
}


void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		ft_putstr(line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}