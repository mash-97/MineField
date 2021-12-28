
def parent(id, array):
    if array[id]==id:
        return id
    array[id] = parent(array[id], array)
    return array[id]

def set_parent(id, pid, array):
    array[parent(id, array)] = parent(pid, array)

def main():
    N, Q = map(lambda x: int(x), input().split(' '))
    print(f"N: {N}, Q: {Q}")

    array = [i for i in range(N+1)]
    for i in range(Q):
        xxx = list(map(lambda x: int(x), input().split(' ')))
        print(xxx)
        if xxx[0]==0:
            set_parent(xxx[2], xxx[1], array)
        else:
            print(f"id: {xxx[1]} -- pid: {parent(xxx[1], array)}")

main()
