class Node:
    def __init__(self, id):
        self.id = id
        self.value = None 
        self.edges = {}

    def edgify(node_a, node_b, value):
        node_a.edges[node_b] = value
        node_b.edges[node_a] = value
        return None 

def dfsMaxTrucks(node, parent=None):
    if len(node.edges)==0:
        if parent:
            return min(node.value, node.edges[parent]) 
        return node.value 
    
    for adj_node, edge_value in node.edges.items():
        if adj_node==parent: continue
        node.value += dfsMaxTrucks(adj_node, parent=node)
    
    if parent:
        return min(node.value, node.edges[parent])
    return node.value


def main():
    N, Z = list(map(int, input().split(' ')))
    nodes = [Node(i+1) for i in range(N)]
    for i in range(N-1):
        U, V, Y = list(map(int, input().split(' ')))
        Node.edgify(nodes[U-1], nodes[V-1], Y)
    
    for i, v in enumerate(list(map(int, input().split(' ')))):
        nodes[i].value = v 
    
    print(dfsMaxTrucks(nodes[Z-1]))


if __name__=='__main__':
    main()
