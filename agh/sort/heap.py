import sys

"""
implementation of heap sort
Time complexity: O(nlogn)
Extra memory: O(1)

data: one line, where first number = amount of intigers in an array 
"""

def sort(v: list[int]) -> None:
    def parent(i: int): return (i-1)//2
    def left(i: int): return i*2 + 1
    def right(i: int): return i*2 + 2

    def repair(v: list[int], i: int, n: int) -> None: #moves a single element in heap until it is in good position
        m = i
        if(left(i) < n and v[left(i)] > v[m]): m = left(i)
        if(right(i) < n and v[right(i)] > v[m]): m = right(i)
        v[i],v[m] = v[m], v[i]
        if(i != m): repair(v, m, n)
    #end def

    def build(v: list[int], n) -> None: #build heap from given array by repairing
        for i in range(parent(n-1), -1, -1): repair(v, i, n)
        return
    #end def

    def sort_heap(v: list[int], n) -> None: #using swap + repair to sort
        for i in range(n, 0, -1):
            v[0], v[i - 1] = v[i - 1], v[0]
            repair(v, 0, i-1)
    #end def

    n = len(v)
    build(v, n)
    sort_heap(v, n)
    return 
#end def

data = list(map(int, sys.stdin.read().split()))
n = data[0]
v = data[1:]

sort(v)
print(v)


