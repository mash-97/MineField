for t in range(int(input())):
  n = int(input())
  maxsum = sum([abs((_+1)-__) for _, __ in enumerate(range(n, 0, -1))])
  print((maxsum//2)+1)

