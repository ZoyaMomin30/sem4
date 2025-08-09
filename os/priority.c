#include <stdio.h>

// Function to Calculate waiting time,
// average waiting time, and average turnaround time
void CalculateTimes(int at[], int bt[], int priority[], int N)
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

    // Sort processes based on priority
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (priority[j] > priority[j + 1] || (priority[j] == priority[j + 1] && at[j] > at[j + 1]))
            {
                int temp = bt_copy[j];
                bt_copy[j] = bt_copy[j + 1];
                bt_copy[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
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
    printf("PN\tAT\tBT\tPriority\tWT\tTAT\tCT\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", process[i], at[process[i] - 1], bt[process[i] - 1], priority[i], wt[i], tat[i], ct[i]);
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
    int bt[] = {10, 3, 8, 2, 5};

    // Array for Priority
    int priority[] = {2, 1, 3, 5, 4}; 

    // Function call to calculate times
    CalculateTimes(at, bt, priority, N);

    // Function call to print Gantt Chart
    PrintGanttChart(at, bt, N);

    return 0;
}
//round robin

// #include <stdio.h>

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
    int bt[] = {9, 10, 1, 5, 2};

    // Time quantum
    int quantum = 2;

    // Function call to calculate times
    CalculateTimes(at, bt, quantum, N);

    return 0;
}
