n, k = list(map(int, input().strip().split(" ")))

for _ in range(k):
  if n%10!=0:
    n -= 1
  else:
    n = n//10

print(n)

