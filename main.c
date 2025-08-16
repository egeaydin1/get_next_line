#include "get_next_line.h"
int main() {
    int fd = open("test1.txt", O_RDWR);
    char *line = get_next_line(fd);
    printf("Dönen satır: '%s'\n", line);
    printf("Uzunluk: %zu\n", ft_strlen(line));
    line = get_next_line(fd);
    printf("Dönen satır: '%s'\n", line);
    printf("Uzunluk: %zu\n", ft_strlen(line));
    free(line);
    close(fd);
}