import sys
import math

for line in sys.stdin:
  if len(line.strip()) == 0:
      break
  n = int(line)
  s = str(math.factorial(n)).strip('0')
  print('{:5} -> {}'.format(n, s[len(s)-1]))
