
def gcd(a, b):
  if a==b: return a
  if a==0: return b
  if b==0: return a
  return gcd(b, a%b)

def tutorial_solution(arr):
  numbers = [-1 for _ in range(1001)]
  for i,e in enumerate(arr):
    numbers[e] = i
  max_sol = -1
  for i in range(1001):
    if numbers[i]==-1: continue
    for j in range(1001):
      if numbers[j]==-1: continue
      if max_sol<numbers[i]+numbers[j]+2 and gcd(i, j)==1:
        max_sol = numbers[i]+numbers[j]+2
  return max_sol


if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    m = -1
    # for i in range(n):
    #  for j in range(n):
    #    if m<i+j+2 and gcd(a[i], a[j])==1:
    #      m = i+j+2

    m = tutorial_solution(a)
    print(m)


