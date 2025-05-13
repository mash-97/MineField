if __name__=='__main__':
  for t in range(int(input())):
    n, m, l, r = list(map(int, input().strip().split(' ')))
    xl=xr=0
    if m>=abs(l):
      m -= abs(l)
      xl = l
    else:
      xl = -m
      m = 0

    if m>0:
      xr = m
    print(xl, xr)


