import numpy as np
import random
random_numbers = np.random.randint(0, 100, size=10)
print("Random Numbers:", random_numbers)
mean = np.mean(random_numbers)
print("Mean:", mean)
std_dev = np.std(random_numbers)
print("Standard Deviation:", std_dev)
max_value = np.max(random_numbers)
min_value = np.min(random_numbers)
print("Maximum Value:", max_value)
print("Minimum Value:", min_value)