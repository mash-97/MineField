import math

for t in range(int(input())):
  n = int(input())
  a = list(map(int, input().strip().split(' ')))

  pref = [a[0]]
  [pref.append(math.gcd(pref[-1], a[indx])) for indx in range(n-1)]
  sref = [a[-1]]
  [sref.append(math.gcd(sref[-1], a[indx])) for indx in range(n-2, -1, -1)]
  sref.reverse()

  indx = -1
  if a[0] != sref[1]:
    indx = 0
  elif a[-1] != pref[-2]:
    indx = n-1
  else:
    for i in range(1, n-1):
      if a[i]!=math.gcd(pref[i-1], sref[i+1]):
        indx = i
        break
  
  if indx!=-1:
    print('Yes')
    print(*[1 if i!=indx else 2 for i in range(n)])
  else:
    print('No')

