#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void) {
	int fd = -1;
	char *str = NULL;

	if ((fd = open("./file.txt", O_RDONLY)) == -1)
		exit(EXIT_FAILURE);

	do {
		str = get_next_line(fd);
		if (!str) break;
		printf("%s", str);
		free(str);
	} while(str);

	close(fd);
	return 0;
}