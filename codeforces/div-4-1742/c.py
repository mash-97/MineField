

def check_red(r, n, arr):
  ans = True
  for c in range(n):
    ans = ans and arr[r][c]=='R'
  return ans

def check_blue(c, n, arr):
  ans = True
  for r in range(n):
    ans = ans and arr[r][c]=='B'
  return ans


if __name__=='__main__':
  for t in range(int(input())):
    input()
    arr = []
    for _ in range(8):
      arr.append(list(input().strip()))

    if any([check_red(r, 8, arr) for r in range(8)]):
      print('R')
    
    if any([check_blue(c, 8, arr) for c in range(8)]):
      print('B')

