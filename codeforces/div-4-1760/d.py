def is_valley(n, a, valleys):
  for v in valleys:
    ans = True
    ans = ans and (v[0]==0 or (v[0]!=0 and a[v[0]-1]>a[v[0]]))
      
    ans = ans and (v[1]==n-1 or (v[1]!=n-1 and a[v[1]+1]>a[v[1]]))
    if ans:
      return True
  return False


for t in range(int(input())):
  n = int(input())
  a = list(map(int, input().strip().split(' ')))

  valleys = []
  indx = 1
  l = 0
  r = -1
  while indx < n:
    if a[indx]==a[indx-1]:
      r = indx
    elif r!=-1:
      valleys.append((l, r))
      r = -1
    if r==-1:
      l = indx
    indx += 1
  print(f"a: {a}")
  print(f"v: {valleys}")
  print()
  if is_valley(n, a, valleys):
    print('yes')
  else:
    print('no')

