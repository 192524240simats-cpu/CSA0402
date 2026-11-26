/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 1. Create a process with fork(); display PID and PPID using system calls
 */
/* Create a process with fork(); display PID and PPID using system calls */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void){
    setvbuf(stdout, NULL, _IOLBF, 0);   /* line-buffered so fork() does not duplicate output */
    printf("Before fork: PID=%d, PPID=%d\n", getpid(), getppid());
    pid_t pid = fork();
    if (pid < 0) { perror("fork failed"); return 1; }
    if (pid == 0) {
        printf("[Child ] PID=%d, Parent PID=%d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);
    printf("[Parent] PID=%d, Child PID=%d\n", getpid(), pid);
    printf("Child has terminated; parent exits.\n");
    return 0;
}
