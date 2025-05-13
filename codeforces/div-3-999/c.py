if __name__=="__main__":
  n, k = list(map(int, input().strip().split(' ')))
  s = list(input().strip())

  a = [[] for _ in range(26)]

  [a[ord(c)-ord('a')].append(indx) for indx, c in enumerate(s)]

  for x in a:
    if k!=0 and len(x)!=0:
      m = min(k, len(x))
      for _ in range(m):
        s[x[_]] = chr(ord('a')-1)
      k -= m
    if k==0:
      break
  
  s = list(filter(lambda c: ord(c)>=ord('a'), s))
  print(''.join(s))

