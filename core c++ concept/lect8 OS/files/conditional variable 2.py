import threading
import time

# Create a condition object
condition = threading.Condition()
shared_resource = []

def producer():
    with condition:
        print("Producer is producing an item")
        shared_resource.append(1)
        print("Producer added an item to the shared resource")
        condition.notify()  # Notify a waiting consumer

def consumer():
    with condition:
        while not shared_resource:
            print("Consumer is waiting for an item")
            condition.wait()  # Release the lock and wait to be notified
        print("Consumer consumed an item from the shared resource")
        shared_resource.pop()

if __name__ == '__main__':
    # Create producer and consumer threads
    producer_thread = threading.Thread(target=producer)
    consumer_thread = threading.Thread(target=consumer)

    # Start the consumer thread first
    consumer_thread.start()
    time.sleep(1)  # Ensure the consumer starts waiting before the producer adds an item

    # Start the producer thread
    producer_thread.start()

    # Wait for both threads to complete
    producer_thread.join()
    consumer_thread.join()
