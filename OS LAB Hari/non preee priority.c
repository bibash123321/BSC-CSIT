#include <stdio.h>

struct Process {
    int id, arrival, burst, priority;
    int remaining, completion, waiting, turnaround;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time, Burst Time, Priority (higher number = higher priority) for P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].remaining = p[i].burst;
    }

    int completed = 0, time = 0;
    int totalTAT = 0, totalWT = 0;

    printf("\nGantt Chart: ");

    while (completed < n) {
        int idx = -1;
        int highest_priority = -1;

        // Find the highest priority process that has arrived and not finished
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].priority > highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("P%d ", p[idx].id); // Gantt Chart output
            p[idx].remaining--;
            time++;

            // If process finishes now
            if (p[idx].remaining == 0) {
                completed++;
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                totalTAT += p[idx].turnaround;
                totalWT += p[idx].waiting;
            }
        } else {
            // No process is ready
            printf("Idle ");
            time++;
        }
    }

    // Print results
    printf("\n\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].arrival, p[i].burst, p[i].priority,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWT / n);

    return 0;
}
