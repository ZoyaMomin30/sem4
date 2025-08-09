#include <stdio.h>

// Function to Calculate waiting time,
// average waiting time, and average turnaround time
void CalculateTimes(int at[], int bt[], int N)
{
    // Declare the arrays for waiting time,
    // turnaround time, and completion time
    int wt[N], tat[N], ct[N], bt_copy[N], process[N];

    // Copy burst times to maintain the original array
    for (int i = 0; i < N; i++)
    {
        bt_copy[i] = bt[i];
        process[i] = i + 1;
    }

    // Sort processes based on burst time
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (bt_copy[j] > bt_copy[j + 1])
            {
                int temp = bt_copy[j];
                bt_copy[j] = bt_copy[j + 1];
                bt_copy[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    // Calculate completion time for each process
    ct[0] = bt_copy[0];
    for (int i = 1; i < N; i++)
    {
        ct[i] = ct[i - 1] + bt_copy[i];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < N; i++)
    {
        tat[i] = ct[i] - at[process[i] - 1];
    }

    // Calculate waiting time for each process
    for (int i = 0; i < N; i++)
    {
        wt[i] = tat[i] - bt[process[i] - 1];
    }

    // Print process details
    printf("PN\tAT\tBT\tWT\tTAT\tCT\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], at[process[i] - 1], bt[process[i] - 1], wt[i], tat[i], ct[i]);
    }

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

// Function to print Gantt Chart
void PrintGanttChart(int at[], int bt[], int N)
{
    printf("\n\nGantt Chart:\n\n");

    // Printing process numbers
    for (int i = 0; i < N; i++)
    {
        printf("| P%d ", i + 1);
    }
    printf("|\n");

    // Printing bars representing processes
    int total_time = 0;
    for (int i = 0; i < N; i++)
    {
        printf("%d   ", total_time);
        total_time += bt[i];
    }
    printf("%d\n\n", total_time);
}

// Driver code
int main()
{
    // Number of process
    int N = 5;

    // Array for Arrival time
    int at[] = {0, 1, 2, 3, 4};

    // Array for Burst Time
    int bt[] = {6, 1, 8, 2, 5};

    // Function call to calculate times
    CalculateTimes(at, bt, N);

    // Function call to print Gantt Chart
    PrintGanttChart(at, bt, N);

    return 0;
}
