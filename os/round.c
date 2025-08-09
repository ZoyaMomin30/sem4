#include <stdio.h>

// Function to Calculate waiting time,
// average waiting time, and average turnaround time
void CalculateTimes(int at[], int bt[], int quantum, int N)
{
    // Declare the arrays for waiting time,
    // turnaround time, and completion time
    int wt[N], tat[N], ct[N], remaining_bt[N];

    // Initialize remaining burst time
    for (int i = 0; i < N; i++)
    {
        remaining_bt[i] = bt[i];
    }

    // Initialize time and current completion time
    int time = 0, current_ct = 0;

    // Process until all processes are done
    while (1)
    {
        int done = 1; // Assume all processes are done initially

        // Traverse all processes
        for (int i = 0; i < N; i++)
        {
            // If burst time is remaining for this process
            if (remaining_bt[i] > 0)
            {
                done = 0; // There are still processes remaining

                // Execute this process for a quantum or remaining time, whichever is smaller
                if (remaining_bt[i] > quantum)
                {
                    // Update time and remaining burst time
                    time += quantum;
                    remaining_bt[i] -= quantum;
                }
                else
                {
                    // Update time and remaining burst time
                    time += remaining_bt[i];
                    remaining_bt[i] = 0;

                    // Calculate completion time for this process
                    ct[i] = time;
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)
            break;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < N; i++)
    {
        tat[i] = ct[i] - at[i];
    }

    // Calculate waiting time for each process
    for (int i = 0; i < N; i++)
    {
        wt[i] = tat[i] - bt[i];
    }

    // Print process details
    printf("PN\tAT\tBT\tWT\tTAT\tCT\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    // Print Gantt Chart
    printf("\n\nGantt Chart:\n\n");

    // Print timeline
    for (int i = 0; i < time; i++)
    {
        printf("-");
    }
    printf("\n|");

    // Print process execution
    for (int i = 0; i < N; i++)
    {
        int execution_time = 0;
        for (int j = 0; j < time; j++)
        {
            if (j >= at[i] && j < ct[i])
            {
                printf("P%d", i + 1);
                execution_time++;
            }
            else
            {
                printf(" ");
            }
        }
        for (int j = 0; j < quantum - execution_time; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");

    // Print timeline
    for (int i = 0; i < time; i++)
    {
        printf("-");
    }
    printf("\n");

    // Calculate average waiting time and average turnaround time
    float avg_wt = 0.0, avg_tat = 0.0;
    for (int i = 0; i < N; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= N;
    avg_tat /= N;

    // Print average waiting time and average turnaround time
    printf("\nAverage waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);
}

// Driver code
int main()
{
    // Number of process
    int N = 5;

    // Array for Arrival time
    int at[] = {0, 1, 2, 3, 4};

    // Array for Burst Time
    int bt[] = {4, 3, 1, 2, 5};

    // Time quantum
    int quantum = 2;

    // Function call to calculate times and draw Gantt chart
    CalculateTimes(at, bt, quantum, N);

    return 0;
}
