for t in range(int(input())):
  strings = [list(input().strip()) for _ in range(8)]
  strings = [''.join([x[i] for x in strings]).replace(".","") for i in range(8)]
  print("".join(strings))




