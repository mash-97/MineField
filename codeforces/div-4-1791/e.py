import heapq



if __name__=='__main__':
  for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    
    curr_sum = sum(a)

    b = [(e, i) for i, e in enumerate(a)]
    b = list(filter(lambda x: x[0]<0, b))
    heapq.heapify(b)

    max_sum = curr_sum
    while len(b)!=0:
      currx = heapq.heappop(b)
      if currx[0]>0:
        continue

      prevx = None
      if currx[1]>0 and abs(a[currx[1]-1]) <= abs(currx[0]):
        prevx = (a[currx[1]-1], currx[1]-1)

      nextx = None
      if currx[1]<n-1 and abs(a[currx[1]+1]) < abs(currx[0]):
        nextx = (a[currx[1]+1], currx[1]+1)
      
      probx = None
      if prevx!=None and nextx==None:
        probx = prevx
      elif prevx!=None and nextx!=None and prevx[0]<nextx[0]:
        probx = prevx
      elif prevx==None and nextx!=None:
        probx = nextx
      elif prevx!=None and nextx!=None and prevx[0]>nextx[0]:
        probx = nextx
      
      if probx:
        curr_sum += (2*currx[0])*(-1)
        curr_sum += (2*probx[0])*(-1)
        a[currx[1]] *= -1
        a[probx[1]] *= -1
        if curr_sum > max_sum:
          max_sum = curr_sum

        if probx[0]>0:
          heapq.heappush(b, (probx[0]*(-1), probx[1]))

    print(max_sum)

