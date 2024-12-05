from multiprocessing import Process
import time 

def cpu_bound_task():
    total = 0
    for _ in range(10**10):
        total += 1
    print("Task complete")

# Creating two processes to run the CPU-bound task
process1 = Process(target=cpu_bound_task)
process2 = Process(target=cpu_bound_task)

start_time = time.time()

process1.start()
process2.start()

process1.join()
process2.join()

print(f"Time taken: {time.time() - start_time} seconds")
