for t in range(int(input())):
  s = input().strip()
  count = 0
  for indx, c in enumerate("codeforces"):
    if c!=s[indx]:
      count += 1
  print(count)

