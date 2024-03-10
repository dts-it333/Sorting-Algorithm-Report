import time
import numpy

n = 0
a = []
with open("random8.txt", "r") as file:
    n = int(file.readline())
    for x in file.readline().strip().split():
        a.append(int(x))

start = time.time()

b = numpy.sort(a)

end = time.time()

execution_time = end - start

print(execution_time)

