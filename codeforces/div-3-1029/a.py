

n, k = list(map(int, input().strip().split(' ')))
t = input().strip()

s = f"{t}"
for _k in range(k-1):
  ts = f"{t}"
  for i in range(n-1, 0, -1):
    r = t.startswith(s[(len(s)-i):])
    if r:
      ts = ts[i:]
      break
  s += ts
print(s)


