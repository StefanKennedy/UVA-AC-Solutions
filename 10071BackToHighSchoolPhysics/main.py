import sys

for line in sys.stdin:
  z = [float(x) for x in line.split()]
  if z[1] == 0:
    print(0)
    continue
  a = z[0] / z[1]
  print(round(a*((z[1]*2)**2)*0.5))
