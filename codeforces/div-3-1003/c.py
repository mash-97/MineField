
def heat_intensity(n, a, pa, k):
  i = 0
  j = k-1
  max_avg = -1
  while j<n:
    curr_sum = pa[j]-pa[i]+a[i]
    curr_avg = curr_sum/(j-i+1)
    max_avg = max(max_avg, curr_avg)
    i+=1
    j+=1
  return max_avg

if __name__=="__main__":
  n, k = list(map(int, input().strip().split(' ')))
  a = list(map(int, input().strip().split(' ')))
  pa = [a[0]]
  for indx in range(1, n):
    pa.append(pa[indx-1]+a[indx])
  
  max_avg = -1
  for _k in range(k, n+1):
    max_avg = max(max_avg, heat_intensity(n, a, pa, _k))
  print(max_avg)

