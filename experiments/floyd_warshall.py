import math

def floyd_warshall(cost_matrix):
  nv = len(cost_matrix)

  for k in range(0, nv):
    for i in range(0, nv):
      for j in range(0, nv):
        cost_matrix[i][j] = min(cost_matrix[i][k]+cost_matrix[k][j], cost_matrix[i][j])

  return cost_matrix


if __name__=='__main__':
  nv = int(input("number of vertices (starting at 1): "))

  # initialize cost matrix with infinity
  # 1 indx based
  cost_matrix = [[math.inf for _ in range(nv+1)] for _ in range(nv+1)]

  # initialize cost of same node to zero
  for _ in range(nv+1):
    cost_matrix[_][_] = 0

  ne = int(input("number of edges: "))

  for _ in range(ne):
    a, b, v = list(map(lambda x: int(x), input().strip().split()))
    cost_matrix[a][b] = v

  print("Initial Cost Matrix: ")
  for _ in range(0, nv+1):
    print(cost_matrix[_])

  print()
  floyd_warshall(cost_matrix)
  print("After Running Floyd Warshall: ")
  for _ in range(0, nv+1):
    print(cost_matrix[_])

