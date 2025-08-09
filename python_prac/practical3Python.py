import os
def append_and_display(filename, data):
    # Open the file in append mode
    with open(filename, 'a') as file:
        # Append data to the file
        file.write(data + '\n')
    
    # Read and display the entire content of the file
    with open(filename, 'r') as file:
        content = file.read()
        print()
        print("Content of", filename, "after appending data:")
        print()
        print(content)
filename = 'FileDir.txt'

data_to_append = input("Enter data to append: ")
append_and_display(filename, data_to_append)

def counting(filename):
    num_lines = 0
    num_words = 0
    num_chars = 0

    with open(filename, 'r') as file:
        for line in file:
            # Count lines
            num_lines += 1
            # Count words
            words = line.split()
            num_words += len(words)
            # Count characters
            num_chars += len(line)

    return num_lines, num_words, num_chars



filename = 'FileDir.txt' 
lines, words, chars = counting(filename)
print("Number of lines:", lines)
print("Number of words:", words)
print("Number of characters:", chars)
print()


def print_file_directory(filename):
    files = os.listdir()
    for file in files:
        if os.path.isfile(file):
            print(file)

print_file_directory(filename)
