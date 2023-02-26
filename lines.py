import os
directory = os.getcwd()
lineCount = 0
charCount = 0

for root, dirs, files in os.walk(directory):
    for file in files:
        if (file.endswith(".cpp") or file.endswith(".h") or file.endswith(".frag") or file.endswith(".vert")) and not "cmake-build" in root:
            with open(os.path.join(root, file), "r") as auto:
                count2 = 0
                for count, line in enumerate(auto):
                    count2 += len(line)
                print(os.path.join(os.path.relpath(root, directory),file) + ": " + str(count) + " lines, " + str(count2) + " characters")
                lineCount += count
                charCount += count2

print("\nTotal lines of code: " + str(lineCount) + "\nTotal characters: " + str(charCount))

while 1 == 1:
    x = 1