class Node:
    def __init__(self, id, adjacents=[]):
        self.id = id
        self.adjacents = adjacents
        self.visited = False
        self.noe = len(self.adjacents)
    
    def add_adjacent(self, adj_node):
        self.adjacents.append(adj_node)
        self.noe += 1
    
    def connect(node1, node2):
        node1.add_adjacent(node2)
        node2.add_adjacent(node1)


def checkIfSameTree(node1, node2):
    if node1.noe != node2.noe:
        return False
    if node1.noe == 0:
        return True
    
    for n1 in node1.adjacents:
        if n1.visited: continue
        for n2 in node2.adjacents:
            if n2.visited: continue
            n1.visited = True
            n2.visited = True
            if checkIfSameTree(n1, n2): return True
            n1.visited = False
            n2.visited = False
            
    return False


                

def main():
    try:
        N = int(input())
        m1 = [Node(id=i+1) for i in range(N)]
        m2 = [Node(id=i+1) for i in range(N)]
        for i in range(N-1):
            a, b = list(map(int, input().split(' ')))
            Node.connect(m1[a-1], m1[b-1])
        
        for i in range(N-1):
            a, b = list(map(int, input().split(' ')))
            Node.connect(m2[a-1], m2[b-1])
        
        check = False
        for n1 in m1:
            for n2 in m2:
                n1.visited = True
                n2.visited = True
                check |= checkIfSameTree(n1, n2)
                if check: break
                n1.visited = False
                n2.visited = False
        
        if check:
            print("S")
        else:
            print("N")
    except Exception as e:
        print(e)
        
        
        
if __name__=='__main__':
    main()
