for t in range(int(input())):
  C = ord('A')+ord('B')+ord('C')
  ans = None
  for _ in range(3):
    s = sum(map(ord, input().strip()))
    if s!=C:
      ans = chr(C-(s-ord('?')))
  print(ans)

