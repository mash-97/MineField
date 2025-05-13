if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    s1 = list(input().strip())
    s2 = list(input().strip())
    ans = True
    for i in range(n):
      ans = ans and (s1[i]==s2[i] or (s1[i] in ['G', 'B'] and s2[i] in ['G', 'B']))
    if ans:
      print('yes')
    else:
      print('no')

