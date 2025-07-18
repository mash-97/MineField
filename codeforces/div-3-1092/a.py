for t in range(int(input())):
  n, k = list(map(int, input().strip().split(' ')))
  a = n//k
  b = n-a*k
  s = 'a'*(a+b)
  for i in range(1,k):
    s += chr(ord('a')+i)*a
  print(s)

