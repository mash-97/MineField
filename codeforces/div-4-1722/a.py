if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    s = input().strip()
    s = list(s)
    name = list("Timur")
    ans = len(s)==len(name)
    for nc in name:
      ans = ans and nc in s
    if ans:
      print('yes')
    else:
      print('no')

