import threading
import time
from multiprocessing import process

def cpu_bound_task():
    print("start")
    total = 0
    for _ in range(10**10):
        total =total+1
        #print(total)
    print("end")

def thread():
    thread1 =threading.Thread(target=cpu_bound_task)
    thread2 =threading.Thread(target=cpu_bound_task)

    start_time = time.time()

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    print(f"time taken:{time.time()-start_time} seconds")

thread()





