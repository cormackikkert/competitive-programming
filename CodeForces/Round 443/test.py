import itertools
T = 1
from subprocess import check_output
import random
import os

def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1)
    out2 = open(file2)
    return out1.read() == out2.read()

count = 0
while True:
    count += 1
    print(count)
    if count % 10 == 0:
        print("Tested", count)
    with open("test.txt", "w") as file:
        N = 7
        file.write(f"{N} 2 2\n")
        lst = [random.randint(1, 3) for i in range(N)]
        file.write(" ".join(map(str, lst)))

    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)

    os.system("B.exe < test.txt > out1.txt")
    os.system("B2.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
