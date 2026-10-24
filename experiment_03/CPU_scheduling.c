#include <stdio.h>

int main() {
    int A[100][4]; // Column 0: PID, Column 1: BT, Column 2: WT, Column 3: TAT
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    printf("Enter number of process: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1; 
    }

    // Sorting processes based on Burst Time (SJF Logic)
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1]) {
                index = j;
            }
        }
        // Swap Burst Time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        // Swap Process ID
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    // Calculating Waiting Time (WT)
    A[0][2] = 0; 
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1];
        }
    }

    // Calculating average WT
    total = 0;
    for (i = 0; i < n; i++) {
        total += A[i][2];
    }
    avg_wt = (float)total / n;

    // Calculating Turnaround Time (TAT) and totals for averages
    total = 0; 
    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2]; // TAT = BT + WT
        total += A[i][3];
        printf("P%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }

    avg_tat = (float)total / n;

    printf("\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f\n", avg_tat);

    return 0;
}
