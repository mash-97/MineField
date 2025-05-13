for t in range(int(input())):
  L, v, l, r = list(map(int, input().strip().split(' ')))
  a = ((r-l)//v)+int(l%v==0 and r%v==0)
  print((L//v)-a)


