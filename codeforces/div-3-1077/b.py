n = int(input())
a = list(map(int, input().strip().split(' ')))
k = 0
for i in range(1, n-1):
  if a[i]==0 and a[i-1]==1 and a[i+1]==1:
    a[i-1] = 0
    a[i+1] = 0
    k += 1

print(k)

