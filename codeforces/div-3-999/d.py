if __name__=="__main__":
  n, m = list(map(int, input().strip().split(' ')))
  a = list(map(int, input().strip().split(' ')))

  s = sorted(map(lambda x: [x[1]%m, x[0]], enumerate(a)))

  i = 0
  j = n-1
  k = 0
  steps = n//m
  # print(f"#> s: {s}")
  for r in range(m):
    for step in range(steps):
      ir = ((n-s[i][0])+r) if s[i][0]>r else r-s[i][0]
      jr = ((n-s[j][0])+r) if s[j][0]>r else r-s[j][0]
      # print(f"#> n: {n}, r: {r}, (i,j): {(i,j)} -- {(s[i], s[j])}, ir: {ir}, jr: {jr}")
      if ir<=jr:
        k += ir
        a[s[i][1]] += ir
        i += 1
      else:
        k += jr
        a[s[j][1]] += jr
        j -= 1
  print(k)
  print(*a)

