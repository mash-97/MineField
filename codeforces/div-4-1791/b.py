for t in range(int(input())):
  n = int(input())
  s = input().strip()
  x = y = 0
  for c in s:
    if c=='U':
      x += 1
    elif c=='D':
      x -= 1
    elif c=='R':
      y += 1
    elif c=='L':
      y -= 1
    if x==1 and y==1:
      break
  if x==1 and y==1:
    print("yes")
  else:
    print("no")

