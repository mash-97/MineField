for t in range(int(input())):
  n = int(input())
  s = input().strip()
  rl = n
  if n==1:
    print(1)
    continue

  for indx in range(n//2):
    if s[indx]!=s[-(indx+1)]:
      rl -= 2
    else:
      break
  print(rl)

