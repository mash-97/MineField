for t in range(int(input())):
  a = list(map(int, input().strip().split(' ')))
  if sum(a)-min(a)>=10:
    print('yes')
  else:
    print('no')

