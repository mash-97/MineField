import heapq

def heapsort(iterable):
  h = []
  for v in iterable:
    heappush(h, v)
  return [heappop(h) for _ in range(len(h))]

if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    sarr = set(arr)
    if len(arr)==len(sarr):
      print('yes')
    else:
      print('no')

