import threading
import time

# Create a semaphore object with a maximum count of 3
sem = threading.Semaphore(3)
condition = threading.Condition()

def task(name):
    with condition:
        print(f'{name} is waiting for the condition')
        condition.wait()  # Wait for the condition to be notified
    print(f'{name} is trying to acquire the semaphore')
    with sem:  # Acquire the semaphore
        print(f'{name} has acquired the semaphore')
        time.sleep(2)  # Simulate some work
        print(f'{name} is releasing the semaphore')
    with condition:
        condition.notify_all()  # Notify all threads waiting for the condition

if __name__ == '__main__':
    # Create multiple threads that run the task function
    threads = []
    for i in range(1, 6):
        t = threading.Thread(target=task, args=(f'Thread {i}',))
        threads.append(t)
        t.start()

    # Notify the first batch of threads to start working
    with condition:
        condition.notify_all()

    # Wait for all threads to complete
    for t in threads:
        t.join()



# flow all thread go to wait() and stop working then line 29 start working which notifies all 
#  then things starts from line number 12