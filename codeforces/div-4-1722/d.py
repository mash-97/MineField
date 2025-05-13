

class Line:
  def __init__(self, data):
    self.data = data
    # print(f"@> data: {self.data}")
    self.size = len(self.data)
    self.lstack = self.__class__.build_stack(self.data, 'L', range(self.size//2-1, -1, -1))
    self.rstack = self.__class__.build_stack(self.data, 'R', range((self.size//2), self.size, 1))
    # print(f"@> left_stack: {self.lstack}")
    # print(f"@> right_stack: {self.rstack}")

    self.count_arr = self.__class__.initial_count(self.data)
    self.sum = sum(self.count_arr)
    self.indx = -1
    # print(f"@> count_arr: {self.count_arr}")
    # print(f"@> sum: {self.sum}")

  def __iter__(self): return self

  def __next__(self):
    self.indx += 1
    if self.indx>=self.size: raise StopIteration
    for _ in range(1):
      msp = self.max_stack_pop()
      if msp:
        self.sum += msp
      else:
        break
    return self.sum

  def max_stack_pop(self):
    lstack_len = len(self.lstack)
    rstack_len = len(self.rstack)

    if lstack_len==0 and rstack_len==0:
      return None

    if lstack_len==0 and rstack_len!=0:
      indx = self.rstack[-1]
      count = indx
      char = 'L'
      stack = self.rstack
    elif lstack_len!=0 and rstack_len==0:
      indx = self.lstack[-1]
      count = self.size-indx-1
      char = 'R'
      stack = self.lstack
    else:
      ltop = self.lstack[-1]
      rtop = self.rstack[-1]

      l_count = self.size-ltop-1
      r_count = rtop

      if l_count >= r_count:
        indx = ltop
        count = l_count
        char = 'R'
        stack = self.lstack
      else:
        indx = rtop
        count = r_count
        char = 'L'
        stack = self.rstack

    diff_count = abs(self.count_arr[indx]-count)
    self.count_arr[indx] = count
    self.data[indx] = char
    stack.pop()
    return diff_count


  @staticmethod
  def build_stack(arr, chk_chr, rng):
    stack = []
    for indx in rng:
      if arr[indx]==chk_chr:
        stack.append(indx)
    return stack
  
  @staticmethod
  def initial_count(arr):
    count_arr = []
    for indx, char in enumerate(arr):
      if char=='L':
        count_arr.append(indx)
      else:
        count_arr.append(len(arr)-indx-1)
    return count_arr



if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    s = list(input().strip())
    line = Line(s)
    print(*[l for l in line])
    # print(f"#> data: {line.data}")
    # print(f"#> count_arr: {line.count_arr}")
    # print(f"#> left_stack: {line.lstack}")
    # print(f"#> right_stack: {line.rstack}")



