import heapq

def divisors(n):
  sqr = int((n**(0.5)))+1
  divs = []
  for d in range(1, sqr+1):
    if n%d==0:
      heapq.heappush(divs, d)
      if d!=n//d:
        heapq.heappush(divs, n//d)
  return divs



if __name__=="__main__":
  divs = divisors(int(input()))
  l = len(divs)
  s = list(input().strip())
  print(f"#> divs: {divs}")
  for _ in range(l):
    indx = heapq.heappop(divs)
    x = s[:indx]
    x.reverse()
    s = x+s[indx:]
    print(f"-> {''.join(s)}")
  print(''.join(s))


