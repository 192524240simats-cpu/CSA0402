/*
 * Name        : S Dharinish
 * Register No : 192524240
 * Course      : CSA04 - Operating Systems Lab
 * Experiment  : 5. Non-preemptive priority scheduling (smaller number = higher priority)
 */
/* Non-preemptive priority scheduling (smaller number = higher priority) */
#include <stdio.h>
int main(void){
    int n = 5, at[] = {0,1,2,3,4}, bt[] = {10,5,8,6,3}, pr[] = {3,1,4,2,5};
    int done[5] = {0}, ct[5], t = 0, cnt = 0; float tw = 0, tt = 0;
    printf("Execution order (highest priority among waiting processes):\n");
    while (cnt < n) {
        int s = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && at[i] <= t && (s < 0 || pr[i] < pr[s])) s = i;
        if (s < 0) { t++; continue; }
        printf("t=%2d: P%d (priority %d) runs for %d units\n", t, s+1, pr[s], bt[s]);
        t += bt[s]; ct[s] = t; done[s] = 1; cnt++;
    }
    printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        int tat = ct[i]-at[i], w = tat-bt[i]; tt += tat; tw += w;
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], pr[i], ct[i], tat, w);
    }
    printf("Average waiting time    = %.2f\nAverage turnaround time = %.2f\n", tw/n, tt/n);
    return 0;
}
