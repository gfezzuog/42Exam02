#include "get_next_line.h"

char *get_next_line(int fd)
{
		int i = - 1;
		int rd;
		char *buffer = malloc(999999);
		char c;

		while((rd = read(fd, &c, BUFFER_SIZE * 0 + 1)) > 0)
		{
				buffer[++i] = c;
				if (buffer[i] == '\n')
						break;
		}
		if ((!buffer[i] && !rd) || rd == - 1 || BUFFER_SIZE == 0)
		{
				free(buffer);
				return(NULL);
		}
		i++;
		buffer[i] = '\0';
		return(buffer);
}
