for t in range(int(input())):
  a = list(map(int, input().strip().split(" ")))
  print(sum(a)-(min(a)+max(a)))
