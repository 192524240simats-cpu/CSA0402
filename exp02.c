/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 2. Copy one file to another using open(), read(), write(), close()
 */
/* Copy one file to another using open(), read(), write(), close() */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(void){
    const char *text = "Operating Systems Lab\nSystem calls: open, read, write, close\n";
    int s = open("source.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    write(s, text, strlen(text)); close(s);
    int in = open("source.txt", O_RDONLY);
    int out = open("destination.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (in < 0 || out < 0) { perror("open"); return 1; }
    char buf[128]; ssize_t n; long total = 0;
    while ((n = read(in, buf, sizeof buf)) > 0) { write(out, buf, n); total += n; }
    close(in); close(out);
    printf("Copied %ld bytes from source.txt to destination.txt\n", total);
    printf("Content of destination.txt:\n");
    int f = open("destination.txt", O_RDONLY);
    while ((n = read(f, buf, sizeof buf)) > 0) write(1, buf, n);
    close(f);
    unlink("source.txt"); unlink("destination.txt");
    return 0;
}
