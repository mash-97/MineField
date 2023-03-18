import queue
import heapq
import math

def dijkstra_heapq():
  nv = int(input("number of nodes: "))
  cost = [[None for _ in range(nv)] for _ in range(nv)]
  ne = int(input("number of edges: "))
  for _ in range(ne):
    a, b, v = list(map(lambda x: int(x), input().strip().split(' ')))
    cost[a][b] = v
  print("\ncosts: ", cost)
  print()

  q = [T(0, 0)]
  distance = [math.inf for _ in range(nv)]
  distance[0] = 0
  visited = set()
  count = [0 for _ in range(nv)]
  while(len(q)!=0):
    n = heapq.heappop(q)
    if n.l in visited:
      continue
    visited.add(n.l)
    count[n.l] += 1
    for indx in range(nv):
      if(cost[n.l][indx]!=None and distance[n.l]+cost[n.l][indx]<distance[indx]):
        distance[indx] = distance[n.l]+cost[n.l][indx]
        heapq.heappush(q, T(indx, distance[indx]))

  print()
  print(f"count: {count}")
  print(f"distance: {distance}")

class Node:
  def __init__(self, value):
    self.value = value

  def __gt__(self, node):
    return self.value > node.value

  def __lt__(self, node):
    return self.value < node.value

  def __ge__(self, node):
    return self.value >= node.value

  def __le__(self, node):
    return self.value <= node.value

class Edge:
  def __init__(self, node_a, node_b, edge_value):
    self.node_a = node_a
    self.node_b = node_b
    self.edge_value = edge_value

  def __gt__(self, edge):
    return self.edge_value > edge.edge_value

  def __lt__(self, edge):
    return self.edge_value < edge.edge_value

  def __ge__(self, edge):
    return self.edge_value >= edge.edge_value

  def __le__(self, edge):
    return self.edge_value <= edge.edge.value

class T:
  def __init__(self, l, v):
    self.l = l
    self.v = v
  def __gt__(self, t):
    return self.v > t.v
  def __lt__(self, t):
    return self.v < t.v
  def __ge__(self, t):
    return self.v >= t.v
  def __le__(self, t):
    return self.v <= t.v

def dijkstra(graph, root_node):
  pq = queue.PriorityQueue()
  visited_nodes = []
  act = {}
  pq.put(T(root_node, 0))
  act[root_node] = [0, root_node]

  while(not pq.empty()):
    cn = pq.get()
    for an in graph[cn.l].keys():
      if an in visited_nodes:
        continue
      if an not in act.keys():
        act[an] = [act[cn.l][0] + graph[cn.l][an], act[cn.l][1]+an]
      elif (act[cn.l][0] + graph[cn.l][an]) < act[an][0]:
        act[an] = [act[cn.l][0] + graph[cn.l][an], act[cn.l][1]+an]

      pq.put(T(an, act[an][0]))
    visited_nodes.append(cn.l)
  return act

if __name__=='__main__':
  dijkstra_heapq()

if __name__=='':
  number_of_edges = int(input("number of edges: "))
  nodes = {}
  print("enter edges: {node} {node} {edge_value}")
  for _ in range(number_of_edges):
    node_a, node_b, edge_value = input(">> ").strip().split(' ')
    edge_value = int(edge_value)
    if(not node_a in nodes.keys()):
      nodes[node_a] = {}
    if(not node_b in nodes.keys()):
      nodes[node_b] = {}
    nodes[node_a][node_b] = edge_value
    nodes[node_b][node_a] = edge_value

  print(nodes)
  root_node = input("enter root: ").strip()
  print()
  print(dijkstra(nodes, root_node))
  print()
  for n in nodes.keys():
    print(f"For {n} ==> {dijkstra(nodes, n)}")


