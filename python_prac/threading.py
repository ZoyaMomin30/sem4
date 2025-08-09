import threading
import time

def thread_function(name, delay):
    print(f"Thread {name} started")
    for i in range(5):
        print(f"Thread {name}: {i}")
        time.sleep(delay)
    print(f"Thread {name} finished")

def create_threads():
    threads = []
    try:
        num_threads = int(input("Enter the number of threads: "))
        if num_threads < 1:
            raise ValueError("Number of threads must be at least 1.")
        for i in range(1, num_threads + 1):
            delay = float(input(f"Enter delay for thread {i}: "))
            t = threading.Thread(target=thread_function, args=(i, delay))
            threads.append(t)
    except ValueError as e:
        print(f"Error: {e}")
    else:
        for t in threads:
            t.start()
        for t in threads:
            t.join()

if __name__ == "__main__":
    create_threads()
