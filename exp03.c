/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 3. FCFS CPU scheduling: all processes arrive at time 0, no I/O wait
 */
/* FCFS CPU scheduling: all processes arrive at time 0, no I/O wait */
#include <stdio.h>
int main(void){
    int n = 5, bt[] = {10, 5, 8, 12, 6}, wt[5], tat[5], t = 0;
    float tw = 0, tt = 0;
    printf("FCFS Scheduling (arrival time = 0 for all)\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        wt[i] = t; t += bt[i]; tat[i] = t;
        tw += wt[i]; tt += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time    = %.2f\n", tw/n);
    printf("Average turnaround time = %.2f\n", tt/n);
    printf("Gantt chart: ");
    t = 0; printf("0");
    for (int i = 0; i < n; i++) { t += bt[i]; printf(" -P%d- %d", i+1, t); }
    printf("\n");
    return 0;
}
