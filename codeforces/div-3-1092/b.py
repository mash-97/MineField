n = int(input())
a = sorted(list(map(int, input().strip().split(' '))))
s = 0
for i in range(0, n, 2):
  s += abs(a[i]-a[i+1])
print(s)

