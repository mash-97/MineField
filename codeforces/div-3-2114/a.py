for _ in range(int(input())):
  s = int(input())
  ss = int(s**0.5)
  if ss*ss!=s:
    print(-1)
  else:
    print(0, ss)


