def min_changes(grid):
  n = len(grid)
  min_count = 0
  print(f"#>> n: {n}")
  for ri in range((n//2)+1):
    for ci in range(ri, n-ri):
      le = grid[ri][ci]
      re = grid[ci][n-1-ri]
      de = grid[n-1-ri][n-1-ci]
      ue = grid[n-1-ci][ri]
      
      print(f"(ri, ci): {(ri, ci)}")
      print(f"(le, re, de, ue): {(le, re, de, ue)}")

      ae = sum([le, re, de, ue])
      min_count += min(ae, 4-ae)
  return min_count


if __name__=='__main__':
  for t in range(int(input())):
    grid = []
    for _ in range(int(input())):
      row = list(map(int, list(input().strip())))
      grid.append(row)

    print(min_changes(grid))

