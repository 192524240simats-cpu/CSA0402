/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 7. Non-preemptive Shortest Job First (all arrive at time 0) with Gantt chart
 */
/* Non-preemptive Shortest Job First (all arrive at time 0) with Gantt chart */
#include <stdio.h>
int main(void){
    int n = 5, id[] = {1,2,3,4,5}, bt[] = {6,8,7,3,4};
    for (int i = 0; i < n-1; i++)               /* sort by burst time */
        for (int j = 0; j < n-i-1; j++)
            if (bt[j] > bt[j+1]) {
                int t = bt[j]; bt[j] = bt[j+1]; bt[j+1] = t;
                t = id[j]; id[j] = id[j+1]; id[j+1] = t;
            }
    int t = 0; float tw = 0, tt = 0;
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        int w = t; t += bt[i];
        tw += w; tt += t;
        printf("P%d\t%d\t%d\t%d\n", id[i], bt[i], w, t);
    }
    printf("Average waiting time    = %.2f\nAverage turnaround time = %.2f\n", tw/n, tt/n);
    printf("Gantt chart: 0");
    t = 0;
    for (int i = 0; i < n; i++) { t += bt[i]; printf(" |P%d| %d", id[i], t); }
    printf("\n");
    return 0;
}
