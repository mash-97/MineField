
if __name__=='__main__':
  n = int(input())
  s = list(input().strip())
  for d in range(1, n+1):
    if n%d==0:
      x = s[:d]
      x.reverse()
      s = x+s[d:]
  print(''.join(s))

