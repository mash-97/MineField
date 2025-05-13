for t in range(int(input())):
  n = int(input())
  s = input().strip()
  x = []
  for c in s:
    if c=='a' or c=='e':
      x.append('V')
    else:
      x.append('C')

  parts = []
  i = n-1
  while i>-1:
    if x[i]=='C':
      parts.append(s[i-2:i+1])
      i -= 3
    else:
      parts.append(s[i-1:i+1])
      i -= 2
  x = []
  while parts != []:
    x.append(parts.pop())
  print('.'.join(x))

