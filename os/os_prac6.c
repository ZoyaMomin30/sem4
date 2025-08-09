#include <stdio.h>

// Function to Calculate waiting time,
// average waiting time, and average turnaround time
void CalculateTimes(int at[], int bt[], int N)
{
    // Declare the arrays for waiting time,
    // turnaround time, and completion time
    int wt[N], tat[N], ct[N];

    // Calculate completion time for each process
    ct[0] = bt[0];
    for (int i = 1; i < N; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
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

    // Calculate average waiting time and average turnaround time
    float avg_wt = 0.0, avg_tat = 0.0; // Define as float
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
    int bt[] = {4, 3, 1, 2, 5};

    // Function call to calculate times
    CalculateTimes(at, bt, N);

    // Function call to print Gantt Chart
    PrintGanttChart(at, bt, N);

    return 0;
}
