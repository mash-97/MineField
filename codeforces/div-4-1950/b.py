if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    a = '##'
    b = '..'
    curr = a
    for _ in range(n):
      xcurr = curr
      string = ""
      for _ in range(n):
        string += xcurr
        if xcurr==a:
          xcurr = b
        else:
          xcurr = a

      print('\n'.join([string, string]))
      if curr==a:
        curr = b
      else:
        curr = a

