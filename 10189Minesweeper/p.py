
def score(grid, x, y):
  score = 0
  if (x > 0):
    score += 1 if grid[x-1][y] == '*' else 0
    if (y > 0):
      score += 1 if grid[x-1][y-1] == '*' else 0
    if (y < len(grid[x])-1):
      score += 1 if grid[x-1][y+1] == '*' else 0
  if (y>0):
    score += 1 if grid[x][y-1] == '*' else 0
    if (x<len(grid)-1):
      score += 1 if grid[x+1][y-1] == '*' else 0
  if (y < len(grid[x])-1):
    score += 1 if grid[x][y+1] == '*' else 0
    if (x < len(grid)-1):
      score += 1 if grid[x+1][y+1] == '*' else 0
  if (x < len(grid)-1):
    score += 1 if grid[x+1][y] == '*' else 0
  return score

i = 0
try:
  while True:
    i += 1
    inp = input()
    if (inp == ""):
      inp = input()
    x, y = [int(x) for x in inp.split()]
    if (x == 0):
      break
    if i > 1:
      print()
    grid = []
    for x1 in range(x):
      grid.append(input())

    out = []
    for x1 in range(x):
      o = ""
      for y1 in range(y):
        if grid[x1][y1] == '*':
          o = o + "*"
        else:
          o = o + str(score(grid, x1, y1))
      out.append(o)
    print("Field #" + str(i) + ":")
    print("\n".join(out))
except EOFError:
  pass

