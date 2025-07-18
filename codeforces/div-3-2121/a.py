for t in range(int(input())):
  n, s = list(map(int, input().strip().split(' ')))
  x = list(map(int, input().strip().split(' ')))
  if n==1:
    res = abs(s-x[0])
  else:
    x = sorted(x)
    if x[0]<=s and x[-1]>=s:
      if abs(x[0]-s) < abs(x[-1]-s):
        res = abs(x[0]-s)*2+abs(x[-1]-s)
      else:
        res = abs(x[0]-s)+abs(x[-1]-s)*2
    else:
      res = max(abs(x[0]-s), abs(x[-1]-s))
  print(res)


