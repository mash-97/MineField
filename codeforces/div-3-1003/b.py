

a, b, x = list(map(int, input().strip().split(' ')))

if x==1:
  print(('0'*a)+('1'*b))
else:
  mini = (a, '0')
  maxi = (b, '1')
  if a>b:
    mini = (b, '1')
    maxi = (a, '0')

  prefix = ''
  if mini[0]+(mini[0]-1)>x:
    prefix = mini[1]*(
