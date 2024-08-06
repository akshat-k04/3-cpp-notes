import threading

def print_numbers():
    for i in range(10):
        print(i)

# Creating two threads
thread1 = threading.Thread(target=print_numbers)
thread2 = threading.Thread(target=print_numbers)

# Starting the threads
thread1.start()
thread2.start()

# Waiting for both threads to finish
thread1.join()
thread2.join()
