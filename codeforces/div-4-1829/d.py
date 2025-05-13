def is_possible(x, n):
  if x==n:
    return True
  if x>n:
    return False
  if x&1==0:
    if is_possible((x//2)+x, n):
      return True
  return is_possible((x*2)+x, n)

for t in range(int(input())):
  n, m = list(map(int, input().strip().split(' ')))
  if is_possible(m, n):
    print('yes')
  else:
    print('no')

