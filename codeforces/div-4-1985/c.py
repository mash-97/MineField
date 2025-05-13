
def newx(old_arr, curr_sum):
  newa = set([])
  mn = 0
  for e in old_arr:
    if e<curr_sum-e:
      continue
    if e==curr_sum-e:
      mn += 1
    newa.add(e)
  # print(f"@> mn: {mn}, newa: {newa}")
  return [mn, newa]


if __name__=='__main__':
  for t in range(int(input())):
    # print(f"#> t: {t+1}")
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    mn_count = 0
    curr_sum = 0
    ref_arr = []
    for e in a:
      ref_arr.append(e)
      curr_sum += e
      mn, ref_arr = newx(ref_arr, curr_sum)
      if mn!=0: mn_count += 1
    print(mn_count)

