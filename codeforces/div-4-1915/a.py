for i in range(int(input())):
  a, b, c = list(map(int, input().strip().split(' ')))
  if a==b:
    print(c)
  elif b==c:
    print(a)
  else:
    print(b)

