import sys
import math

for line in sys.stdin:
    line = line.strip()
    if line == '*':
        break
    if not line.isdigit(): 
        total = 0
        for i in range(len(line)):
            total += ( 26**(len(line)-i-1) ) * (ord(line[i]) - 96)
        print("{:21} {:,}".format(line, total))
    else:
        s = ''
        i = 0
        num = int(line)
        #while True:
        #s = s + str(math.log(int(line), 26))
        while True:
            rem = num % 26
            if rem == 0: 
                rem = 26
            num -= rem
            num = num // 26
            s = chr((rem + 96)) + s
            if num <= 0:
                break
        print("{:21} {:,}".format(s, int(line)))
        #( 26**(len(line)-i-1) ) * (ord(line[i]) - 96)
