for i in range(int(input())):
  n = int(input())
  square = True
  for _ in range(n):
    if input().strip().count('1')==1:
      square = False
  
  if square:
    print('SQUARE')
  else:
    print('TRIANGLE')

