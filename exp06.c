/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 6. Preemptive priority scheduling (smaller number = higher priority)
 */
/* Preemptive priority scheduling (smaller number = higher priority) */
#include <stdio.h>
int main(void){
    int n = 5, at[] = {0,1,2,3,4}, bt[] = {10,5,8,6,3}, pr[] = {3,1,4,2,5};
    int rem[5], ct[5], done = 0, t = 0, last = -1; float tw = 0, tt = 0;
    for (int i = 0; i < n; i++) rem[i] = bt[i];
    printf("Gantt chart (time: process):\n");
    while (done < n) {
        int s = -1;
        for (int i = 0; i < n; i++)
            if (rem[i] > 0 && at[i] <= t && (s < 0 || pr[i] < pr[s])) s = i;
        if (s < 0) { t++; continue; }
        if (s != last) { printf("t=%2d: P%d\n", t, s+1); last = s; }
        rem[s]--; t++;
        if (rem[s] == 0) { ct[s] = t; done++; }
    }
    printf("t=%2d: end\n\n", t);
    printf("Process\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        int tat = ct[i]-at[i], w = tat-bt[i]; tt += tat; tw += w;
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], pr[i], ct[i], tat, w);
    }
    printf("Average waiting time    = %.2f\nAverage turnaround time = %.2f\n", tw/n, tt/n);
    return 0;
}
