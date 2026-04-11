"""
Task about sorting K-chaotic an array
we are given an array and K-chaos indicator. It means, each number is at most K indexes away from position it would be in a sorted array. 
this gives us possibility to sort it faster than T.sort()

Time complexity: O(nlogk)
Extra memory: O(1)
"""
def parent(i: int) -> int: return (i - 1)//2
def left(i: int) -> int: return i*2 + 1
def right(i: int) -> int: return i*2 + 2

def repair_down(K: list[int], i: int, n: int):
    nw_ind = i
    if(left(i) < n and K[left(i)] < K[i]): nw_ind = left(i)
    if(right(i) < n and K[right(i)] < K[nw_ind]): nw_ind = right(i)
    if(i != nw_ind):
        K[i], K[nw_ind] = K[nw_ind], K[i]
        repair_down(K, nw_ind, n)
    return
#end def
def repair_up(K: list[int], i: int):
    if(i == 0): return #korzen
    ind_r = parent(i)
    if(K[i] < K[ind_r]): 
        K[i], K[ind_r] = K[ind_r], K[i]
        repair_up(K, ind_r)
#end def
def add_element(K: list[int], x: int): 
    K.append(x)
    repair_up(K, len(K) - 1)
#end def
def remove_element(K: list[int], i: int):
    n = len(K)
    if(i == n - 1):
        K.pop()
        return
    K[i] = K[n - 1]
    K.pop()
    repair_down(K, i, n - 1)
#end def

#wersja gdzie T[0] oznacza rozmiar
k = int(input())
T = list(map(int, input().split()))
K = []
n = len(T)
ind = 0
for i in range(n):
    x = T[i]
    add_element(K, x)
    if(len(K) > k):
       T[ind] = K[0]
       remove_element(K, 0)
       ind+=1 
while(len(K) > 0):
    T[ind] = K[0]
    remove_element(K, 0)
    ind+=1 
print(T)
#T2 = [int(x) for x in input().split()]
#print(T2)