
n = int(input())
res = ''
ss = []
mins = '0'*(n+1)
for _ in range((n-1)*2):
  s = input().strip()
  if len(s)<len(mins):
    mins = s
  ss.append(s)

for s in ss:
  print(f"#> s: {s} -- mins: {mins}")
  if s.startswith(mins):
    res += 'P'
    mins = s
  elif mins.startswith(s):
    res += 'P'
  else:
    res += 'S'

print(res)


  
