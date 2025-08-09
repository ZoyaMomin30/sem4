class Process:
    def __init__(self, pid, arrival_time, burst_time):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time

def fcfs(processes):
    processes.sort(key=lambda x: x.arrival_time)
    current_time = 0
    total_waiting_time = 0
    total_turnaround_time = 0
    gantt_chart = []

    for process in processes:
        waiting_time = max(0, current_time - process.arrival_time)
        total_waiting_time += waiting_time
        turnaround_time = waiting_time + process.burst_time
        total_turnaround_time += turnaround_time
        gantt_chart.append((process.pid, current_time, current_time + process.burst_time))
        current_time += process.burst_time

    average_waiting_time = total_waiting_time / len(processes)
    average_turnaround_time = total_turnaround_time / len(processes)
    print("Average Waiting Time:", average_waiting_time)
    print("Average Turnaround Time:", average_turnaround_time)
    
    return gantt_chart, average_turnaround_time

# Example usage
if __name__ == "__main__":
    processes = [
        Process(1, 0, 5),
        Process(2, 1, 3),
        Process(3, 2, 8),
        Process(4, 3, 6)
    ]

    gantt_chart, avg_turnaround_time = fcfs(processes)
    print("Gantt Chart:")
    for p in gantt_chart:
        print("Process", p[0], "starts at", p[1], "and ends at", p[2])
