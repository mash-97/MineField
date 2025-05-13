for t in range(int(input())):
  n = int(input())
  a = list(map(int, input().strip().split(' ')))
  maxl_count = 0
  lcount = 0
  for e in a:
    if e==1:
      if maxl_count < lcount:
        maxl_count = lcount
      lcount = 0
    else:
      lcount += 1
  if maxl_count < lcount:
    maxl_count = lcount
  print(maxl_count)

