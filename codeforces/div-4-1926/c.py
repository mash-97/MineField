dsum = lambda num: sum(map(int, list(str(num))))

mem = [0]
for n in range(1, (2*10**5)+1):
  mem.append(mem[n-1]+dsum(n))

for t in range(int(input())):
  print(mem[int(input())])


