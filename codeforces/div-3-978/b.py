n = int(input())
s = input().strip()
count = 0

indx = 1

lcount = 1 if s[0]=='x' else 0

while indx<n:
  currc = s[indx]
  if currc=='x':
    lcount += 1
    if lcount>2:
      count += 1
  else:
    lcount = 0
  indx += 1

print(count)

