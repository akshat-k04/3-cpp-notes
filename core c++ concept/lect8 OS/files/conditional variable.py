from threading import *
import time

# Create a condition variable object
cond = Condition() 
done = 1 

def task(name):
    global done
    with cond:  # Acquire the condition variable's associated lock
        if done == 1:
            done = 2  # Change the state to indicate a task is waiting
            print("waiting on condition variable cond:", name)
            cond.wait()  # Release the lock and wait for the condition to be notified
            print("Condition met: ", name) 
        else:
            for i in range(5):
                print(".")
                time.sleep(1)  # Simulate work with a sleep

            print("signaling condition variable cond", name)
            cond.notify_all()  # Notify all waiting threads
            print("Notification done", name)

if __name__ == '__main__':
    # Create two threads that run the task function
    t1 = Thread(target=task, args=('t1',)) 
    t2 = Thread(target=task, args=('t2',)) 

    # Start the threads
    t1.start() 
    t2.start() 

    # Wait for both threads to complete
    t1.join()
    t2.join()
