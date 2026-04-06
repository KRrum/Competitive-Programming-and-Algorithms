# this program sorts list of numbers with log n diffrent values in O(nlog(logn))
"""
Specialized Sort for datasets with few unique values.
Complexity: O(n * log(log n)) where the number of unique values k = log(n).

Algorithm Steps:
1. Build a sorted list 'U' of unique values found in 'T'.
2. Count occurrences of each unique value (using binary search to find indices).
3. Reconstruct 'T' in sorted order using the counts.
"""
import sys

def is_in_T(U: list[int], x: int) -> bool: #checks where value x appears in U
    if(len(U) == 0): return None
    l = 0
    p = len(U)
    p-=1
    while(l != p):
        s = (l + p)//2
        if(U[s] == x): return s
        if(U[s] < x): l = s+1
        if(U[s] > x): p = s
    if(U[l] == x): return l
    return None
#end def
def place(U: list[int], x: int) -> bool: #if x value does not appear in U, place that value
    n = len(U)
    ind = 0
    while(ind < n and U[ind] < x): ind+=1
    U.append(0)
    for i in range(n, ind, -1): U[i] = U[i - 1]
    U[ind] = x
#end def

#T = [5, 7, 5, 7, 2, 7, 2, 5, 2, 5, 5, 5, 7] #example
input_data = sys.stdin.read().split()
if not input_data:
    exit()
n = int(input_data[0])
T = [int(x) for x in input_data[1:]]
U = []
for i in range(n):
    x = T[i]
    if(is_in_T(U, x) == None): place(U, x)

n2 = len(U)
Amount = [0]*n2
for i in range(n):
    x = T[i]
    ind = is_in_T(U, x)
    Amount[ind] += 1

l = 0
for i in range(n2):
    for j in range(Amount[i]):
        T[l] = U[i]
        l+=1    

print(T)

