
from collections import deque

# def bruteKnapsack(items, s):
#     itemsd = dict([[item, False] for item in items])
#     sets = []
#     for item in items:
#         dq = deque()
#         tmp = s 
#         if tmp > item[0]:
#             break 
#         elif tmp==item[0]:
#             sets.append([item])
#             continue
#         solution = [item]
#         dq.append(item)
#         while((len(dq)!=0)):
#             cit = dq.pop() 
#             if(tmp==0):
#                 sets.append(solution)
#             for xitem in items:
#                 if not itemsd[xitem] and tmp-xitem[0]>=0:
#                     tmp -= xitem[0]
#                     dq.append(item)
#                     solution.append(item)
#                     itemsd[xitem] = True
#             itemsd[cit] = False

# A naive recursive implementation
# of 0-1 Knapsack problem

# Returns the maximum value that 
# can be put in a knapsack of 
# capacity W
def knapSack(W, wt, val, n):
    # Base Case
    if n==0 or W==0:
        return 0
    
    # If weight of the nth item is
    # more than Knapsack of capacity W,
    # then this item cannot be included 
    # in the optimal solution
    if(wt[n-1]>W):
        return knapSack(W, wt, val, n-1)
    
    # return the maximum of two cases:
    # (1) nth item included
    # (2) not included
    else:
        return max(
            val[n-1] + knapSack(
                W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1))



if __name__=='__main__':
    items = []
    n = int(input())
    for i in range(n):
        items.append(list(map(int, input().split(' '))))
    wt = [item[0] for item in items]
    val = [item[1] for item in items]
    W = int(input())
    print(knapSack(W, wt, val, n))

