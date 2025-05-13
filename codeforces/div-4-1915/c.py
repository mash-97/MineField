for i in range(int(input())):
  n = int(input())
  sum_of_squares = sum(map(int, input().strip().split(' ')))
  root_square = int(str(sum_of_squares**(0.5)).split('.')[1])
  if root_square>0:
    print('no')
  else:
    print('yes')

