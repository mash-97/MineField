
if __name__ == '__main__':
  while True:
    try:
      number_of_sticks = int(input())
      fsticks = 0
      for _ in range(number_of_sticks):
        ss, ns = map(lambda x: int(x), input().split())
        fsticks += (ns-(ns&1))
      
      print(fsticks//4)
        
    except EOFError:
      pass

