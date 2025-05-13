import math

for t in range(int(input())):
  n = int(input())
  a = list(map(int, input().strip().split(' ')))
  me = max(a)
  me_indx = a.index(me)

  indx = 0
  if me_indx==0:
    indx = 1

  gc = a[indx]
  while indx<n:
    if a[indx]==me_indx:
      indx += 1
      continue

    gc = math.gcd(gc, a[indx])
    indx += 1

  if gc==me:
    print('No')
  else:
    print('Yes')
    print(*[1 if me_indx==indx else 2 for indx in range(n)])

  
