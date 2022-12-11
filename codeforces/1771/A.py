if __name__ == '__main__':
  t = int(input())
  for _ in range(t):
    n = int(input())
    numbers = list(map(lambda x: int(x), input().split(' ')))
    mn = min(numbers)
    mx = max(numbers)
    mnc = 0
    mxnc = 0
    for i in numbers:
      if mn == i:
        mnc += 1
      if mx == i:
        mxnc += 1
    if mn==mx:
      mxnc -= 1
    print((mnc*mxnc)*2)

