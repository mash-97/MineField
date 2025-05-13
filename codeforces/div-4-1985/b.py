
def max_x(n):
  maxx = 1
  prev_mulpsum = 1
  for x in range(2, n+1):
    xnd = n//x
    curr_mulpsum = ((xnd*(xnd+1))/2)*x
    if curr_mulpsum > prev_mulpsum:
      maxx = x
      prev_mulpsum = curr_mulpsum
  return maxx

if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    print(max_x(n))

