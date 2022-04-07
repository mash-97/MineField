# partition the array based on assuming pivot as the e_index
def partition(s_index, e_index, array):
  p_index = s_index 
  i = s_index
  while i<e_index:
    if array[i]<array[e_index]:
      array[p_index], array[i] = array[i], array[p_index]
      p_index += 1
    i+= 1
  array[e_index], array[p_index] = array[p_index], array[e_index]
  return p_index 

def quicksort(s_index, e_index, array):
  if s_index>=e_index:
    return None  
  p_index = partition(s_index, e_index, array)
  quicksort(s_index, p_index-1, array)
  quicksort(p_index+1, e_index, array)

if __name__=='__main__':
  array = list(map(lambda x: int(x), input().split()))
  print("before sorting:", ', '.join(list(map(str, array))))
  quicksort(0, len(array)-1, array)
  print("after sorting:", ', '.join(list(map(str, array))))



