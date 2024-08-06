import os

# Number of files to create
num_files = 10

# Directory where the files will be created
output_dir = "C:/Users/HP/programming/3 c++ notes/DSA and CP/placement/DSA/" 

for i in range(25, num_files + 25):
    filename = f"{i} 24 june.cpp"
    filepath = os.path.join(output_dir, filename)

    with open(filepath, 'w') as file:
        file.write('//')