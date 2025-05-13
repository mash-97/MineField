n, k = list(map(int, input().strip().split(' ')))
a = list(map(int, input().strip().split(' ')))

a.sort()
ans = a[k-1]
if k==0:
  ans = 0 
elif k!=n:
  if ans==a[k]:
    ans = -1
  elif ans==10**9:
    pass
  elif ans+1<a[k]:
    ans += 1
print(ans)

