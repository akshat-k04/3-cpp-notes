import numpy as np

def logistic_map(r, x):
    #Logistic map function.
    return r * x * (1 - x)

def generate_kneading_sequence(r, x0, n):
    
    critical_value = 0.5
    sequence = ''
    
    for _ in range(n):
        x0 = logistic_map(r, x0)
        if x0 > critical_value:
            sequence += 'R'
        elif x0 < critical_value:
            sequence += 'L'
        else:
            sequence += 'C'
            break  # Critical value reached end sequence
    
    return sequence

r = 3.8
x0 = 0.2
n = 100
sequence = generate_kneading_sequence(r, x0, n)
print(f"Kneading sequence for r={r}, x0={x0}: {sequence}")