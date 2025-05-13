for t in range(int(input())):
  n = int(input())
  print(max(list(map(lambda c: ord(c)-ord('a')+1, input().strip()))))

