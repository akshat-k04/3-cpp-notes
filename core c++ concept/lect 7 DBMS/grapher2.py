import matplotlib.pyplot as plt

# Read data from file
data = []
with open('output.txt', 'r') as file:
    for line in file:
        time, x, y = map(float, line.split())
        data.append((time, x, y))

# Sort data by time
data.sort(key=lambda x: x[0])

# Plot the graph with lines connecting consecutive points
for i in range(len(data) - 1):
    plt.plot([data[i][1], data[i+1][1]], [data[i][2], data[i+1][2]], 'r-')  # 'r-' for red line

# Plot points
for time, x, y in data:
    plt.plot(x, y, 'ro')  # 'ro' for red circles
    plt.text(x, y, f'{time:.2f}', fontsize=9, ha='right')

plt.xlabel('X Position')
plt.ylabel('Y Position')
plt.title('Bacteria Position over Time')
plt.grid(True)
plt.show()
