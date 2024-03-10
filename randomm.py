from random import *

a = [randint(-1e9, 1e9) for i in range(1000001)]

f = open("random1.txt", "w")
f.write(str(1000000) + "\n")
for i in a:
    f.write(str(i) + " ")
        