from queue import deque

class Graph:
    def __init__(self, *args, **kwargs):
        self.nodes = {}

    def bfs(self, start_node):
        result = []
        q = deque()
        if not start_node in self.nodes.keys():
            raise KeyError(f"{start_node} not found in the graph!")
        q.append(start_node)
        visited = [start_node]
        while len(q) != 0:
            cn = q.popleft()

            print(f"visited: {visited}")
            result.append(cn)
            for an in self.nodes[cn]:
                if not an in visited:
                    visited.append(an)
                    q.append(an)
                    print(f"--> append: {an} for {cn}")


        print()
        return result 


if __name__=='__main__':
    g = Graph()
    g.nodes[1] = [2,3]
    g.nodes[2] = [1,3,4]
    g.nodes[3] = [1,2,4]
    g.nodes[4] = [2,3]
    while True:
        q, w,v = map(lambda x: int(x), input().split(' '))
        if q==-1:
            break

        elif q==0:
            if w in g.nodes.keys():
                g.nodes[w].append(v)
            else:
                g.nodes[w] = [v]
            if v in g.nodes.keys():
                g.nodes[v].append(w)
            else:
                g.nodes[v] = [w]
        else:
            print(f"for {w}: ")
            print(g.bfs(w))
            print()
            print(f"for {v}: ")
            print(g.bfs(v))
