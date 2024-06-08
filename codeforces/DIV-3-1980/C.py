t = int(input())
for _ in range(0, t):
  n = int(input())
  a = [int(_) for _ in input().split()]
  b = [int(_) for _ in input().split()]
  m = int(input())
  d = [int(_) for _ in input().split()]

  if d[m-1] not in b:
    print("No")
    continue

  c = []
  indx = 0
  while indx<n: 
    if a[indx]!=b[indx]:
      c.append(b[indx])
    indx += 1
  
  c = sorted(c)
  d = sorted(d)

  ic = 0
  id = 0
  while ic<len(c) and id<len(d):
    if d[id]==c[ic]:
      ic+=1
      id+=1
    elif d[id]<c[ic]:
      id+=1
    else:
      break

  if ic==len(c):
    print("Yes")
  else:
    print("No")

