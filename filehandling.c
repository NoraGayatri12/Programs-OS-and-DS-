# Open a file in write mode
with open("example.txt", "w") as file:
    file.write("Hello, this is a test file.\n")
    file.write("Another line of text.")

# Open a file in read mode
with open("example.txt", "r") as file:
    content = file.read()
    print(content)

# Open a file in append mode
with open("example.txt", "a") as file:
    file.write("\nThis line was appended.")

# Read the file line by line
with open("example.txt", "r") as file:
    for line in file:
        print(line.strip())