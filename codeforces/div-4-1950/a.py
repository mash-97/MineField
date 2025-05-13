for t in range(int(input())):
  a, b, c, = list(map(int, input().strip().split(' ')))
  if a<b and b<c:
    print("STAIR")
  elif a<b and b>c:
    print("PEAK")
  else:
    print("NONE")


