if __name__=='__main__':
  for t in range(int(input())):
    a, b, c = list(map(int, input().strip().split()))
    ans = False
    ans = ans or (a+b)==c
    ans = ans or (b+c)==a
    ans = ans or (c+a)==b
    if ans:
      print('yes')
    else:
      print('no')

