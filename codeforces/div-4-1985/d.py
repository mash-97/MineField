for t in range(int(input())):
  n, m = list(map(int, input().strip().split(' ')))
  matrx = []
  
  frow_match = None
  lrow_match = None
  for i in range(n):
    matrx.append(input().strip())
    if not frow_match and matrx[-1].find('#')>-1: frow_match = (i, matrx[-1].find('#'))
    if matrx[-1].find('#')>-1: lrow_match = (i, matrx[-1].find('#'))

  fcol_match = None
  lcol_match = None
  for j in range(m):
    col_str = ''.join([matrx[i][j] for i in range(n)])
    if not fcol_match and col_str.find('#')>-1: fcol_match = (j, col_str.find('#'))
    if col_str.find('#')>-1: lcol_match = (j, col_str.find('#'))

  print(lcol_match[1]+1, lrow_match[1]+1)



  
