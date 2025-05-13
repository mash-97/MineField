n, k = list(map(int, input().strip().split(' ')))
a = list(map(int, input().strip().split(' ')))
s = set(a)

if len(s)>=k:
  print("YES")
  print(*[a.index(_)+1 for _ in list(s)[:k])
else:
  print('NO')

