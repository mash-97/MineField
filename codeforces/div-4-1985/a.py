if __name__=='__main__':
  for t in range(int(input())):
    a, b = list(map(list, input().strip().split(' ')))
    a[0], b[0] = b[0], a[0]
    print(''.join(a), ''.join(b))

