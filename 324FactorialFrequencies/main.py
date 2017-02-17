import sys
import math

for line in sys.stdin:
    if len(line.strip()) == 0 or line == '0\n':
         break
    n = int(line)
    s = str(math.factorial(n))
    counts = [0] * 10
    for c in s:
        counts[ord(c)-48] += 1
    print(str(n) + "! --")
    print("   (0) {:4}    (1) {:4}    (2) {:4}    (3) {:4}    (4) {:4}".format(counts[0], counts[1], counts[2], counts[3], counts[4]))
    print("   (5) {:4}    (6) {:4}    (7) {:4}    (8) {:4}    (9) {:4}".format(counts[5], counts[6], counts[7], counts[8], counts[9]))
