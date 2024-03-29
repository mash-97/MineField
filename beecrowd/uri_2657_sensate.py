"""
1. Do not be a sensate.

2. Be a sensible and have no one in the same cluster with programming level greater than five.

3. Be a sensible and have your programming level greater or equal to 5.
"""

def validity_of_participation(person, persons_manifest):
    if len(persons_manifest[person][1]) == 0:
        return True
    elif persons_manifest[person][0] >= 5:
        return True

    for x in persons_manifest[person][1]:
        if persons_manifest[x][0] > 5:
            return False
    return True


def main(local=""):
    if local:
        file = open(local, 'r')
        N, M, Q = map(lambda x: int(x), file.readline().strip().split(' '))
    else:
        N, M, Q = map(lambda x: int(x), input().split(' '))


    persons = {}
    for i in range(N):
        if local:
            x = file.readline().strip().split(' ')
        else:
            x = input().split(' ')
        persons[x[0]] = [int(x[1]), [], False]

    for i in range(M):
        if local:
            x = file.readline().strip().split(' ')
        else:
            x = input().split(' ')
        persons[x[0]][1].append(x[1])
        persons[x[1]][1].append(x[0])

    for person in persons.keys():
        persons[person][2] = validity_of_participation(person, persons)

    for i in range(Q):
        if local:
            x = file.readline().strip()
        else:
            x = input()
        print("S" if persons[x][2] else "N")

if __name__=='__main__':
    main("uri_2657_input.txt")
